public class ListTest{
    static class Entry{
	int column;
	double value;
	Entry(int col, double val){
	    column = col;
	    value = val;
	}

	public boolean equals(Object object){
	    if (object == null || !(object instanceof Entry)) {
		return false;
	    }
	    return (((Entry)object).value == value);
	}

	public String toString(){
	    return "" + column;
	}
    }

    public static void main(String[] args){
	List A = new List();
	List B = new List();
	
      
	for(int i=1; i<=5; i++){
	    A.append(new Entry(i, (double)i));
	    B.append(new Entry(i, (double)i));
	}
	System.out.println(A);
	System.out.println(B);
      
	for(A.moveFront(); A.index()>=0; A.moveNext()){
	    System.out.print(A.get()+" ");
	}


	System.out.println();
	
	System.out.println(A.equals(B));
	System.out.println(B.equals(B));


	A.insertBefore(-1);
	A.moveFront();
	A.insertAfter(-2);
	
	System.out.println(A);
	A.clear();
	System.out.println(A.length());
    }
}