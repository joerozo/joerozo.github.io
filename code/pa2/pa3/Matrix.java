class Matrix{

	private class Entry{
		int column;
		double value;

		Entry(int col, double value){
			this.col = col;
			this.value = value;
		}
	


		public boolean equals(Object p){
			Entry x1 = ((Entry)p).value;
			Entry x2 = ((Entry)p).col;

			if(x1 == value && x1 == column){
				return true;
			}else{
				return false;
			}
	
		}

		public String toString(){
			return(colum + " " +value);
		}
	
	}

	private List [] matrix;
	private int NNZ; 
	
	public Matrix(int n){
		if(n<1){
			System.err.println("StdErr-Please Enter a Valid n-Matrix size");
			System.exit(1);
		}
		Matrix = new List[n];
		for(int i =1; i<=n; i++){
			Matrix[i] = newList();
		}
	}

	public int getSize(){
		return Matrix.length;
	}

	public int getNNZ(){
		return NNZ;
	}

	public boolean equals(object x){
		Matrix comp = (Matrix)x;

		for(int i = 0; i<Matrix.length; i++){
			if(matrix[i].equals(comp.matrix[i])){
				return true;
			}
		}
		return false;
	}

	void makeZero(){
		for(int i = 0; i<matrix.length; i++){
			matrix[i] = clear();
		}
		NNZ = 0;
	}

	Matrix copy(){
		Matrix cop = new Matrix(matrix.length);
		for(int i = 0; i<matrix.length; i++){
			List a = matrix[i];
			List b = cop.matrix[i];

			for(a.moveFront(); a.index >=0; a.moveNext()){
				Object x = a.get();
				Entry aobj = (Entry)x;
				Entry finalEnt = new Entry(aobj.col, aobj.value);
				b.append(finalEnt);
			} 
		}
			cop.NNZ = NNZ;
			return cop;
}
		
	void changeEntry(int i, int j, double x){
		if(i >= 1 && i <= matrix.length && j >= 1 && j <= matrix.length){
			List column = matrix[i];
			for(int c = 0; c < j; c++){
				

			}
		}
	}


	/*
        public boolean equals(Object L){
                node x1 = front;
                node x2 = ((List)L).front;
                while(x1!=null && x2!=null){
                        if(x1.value != x2.value){
                                return false;
                        }
                        x1=x1.next;
                        x2=x2.next;
                }
                return true;
        }
	*/

	//matrix equals(){}
	//List has equals(){}

	//Matrix equals() ---> done by comparing row to row to row to row
	//List equals() ---> compare node to node to node in each list 
	//Node equals() ---> done by comparing value field of each Node to each other 
	//(done by object) object has equals method ex: node1.value.equals-->calls
	//the particular equals method to whatever object is before the dot/one of objects
	//classes personal 11 methods
	//
	//

}


