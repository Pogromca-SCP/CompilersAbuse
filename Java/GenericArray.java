public class GenericArray<T>
{
	// Generic arrays have a certain restriction
	private final T[] arr;
	
	@SafeVarargs
	public GenericArray(T... items)
	{
		// You can't create new generic array directly
		// arr = new T[3];
		
		// However, this restriction can be easily avoided using varargs
		arr = items;
	}
	
	public void print()
	{
		if (arr == null)
		{
			System.out.println("Array is null!");
		}
		else
		{
			for (T item : arr)
			{
				System.out.println(item);
			}
		}
	}
	
	public static void main(String[] args)
	{
		// Without varargs, using another array is required
		// Integer[] tmp = new Integer[3];
		// new GenericArray<Integer>(tmp).print();
		
		new GenericArray<String>("haha", "generics", "go", "brrrr").print();
		new GenericArray<Integer>(34, -15, 5).print();
		new GenericArray<Integer>().print();
	}
}
