class Matrix{


	private class Entry{
		int column;
		double value;

		Entry(int col, double val){
			column = col;
			value = val;
		}

		public String toString(){
			return "("+column+","+value+")";
		}
	}



		/*public boolean equals(Object p){
			//double x1 = (double)p.value;
			//int x2 = p.col;
			Matrix v = (Entry)p;
			for(int i = 0; i < rows.length; i++){
				if(!(rows[i].equals(v.rows[i]))){
					return false;
				}
			}
			return true;
	}*/



	private List [] rows;
	private int NNZ; 
	
	public Matrix(int n){
		if(n<1){
			System.err.println("StdErr-Please Enter a Valid n-Matrix size");
			System.exit(1);
		}

		rows = new List[n];
		for(int i =0; i < n; i++){
			rows[i] = new List();
			NNZ = 0;
		}
	}

	public String toString(){
		StringBuffer x = new StringBuffer();
		for(int i = 0; i < rows.length; i++){
			if (rows[i] == null){ 
				continue;
			}
			x.append((i+1)+ ": ");
			x.append(rows[i]);
			x.append("\n");
		}
		String y = new String (x);
		return y;

	}

	public int getSize(){
		return rows.length;
	}

	public int getNNZ(){
		return NNZ;
	}

	public boolean equals(Object x){
		Matrix comp = (Matrix)x;

		for(int i = 0; i<rows.length; i++){
			if(rows[i].equals(comp.rows[i])){
				return true;
			}
		}
		return false;
	}

	public void makeZero(){
		for(int i = 0; i<rows.length; i++){
			rows[i].clear();
		}
		NNZ = 0;
	}

	public Matrix copy(){
		Matrix cop = new Matrix(rows.length);
		for(int i = 0; i<rows.length; i++){
			List a = rows[i];
			List b = cop.rows[i];

			for(a.moveFront(); a.index() >=0; a.moveNext()){
				Object x = a.get();
				Entry aobj = (Entry)x;
				Entry finalEnt = new Entry(aobj.column, aobj.value);
				b.append(finalEnt);
			} 
		}
		cop.NNZ = NNZ;
		return cop;
	}

	void changeEntry(int i, int j, double x){
		if(i >= 1 && i <= rows.length && j >= 1 && j <= rows.length){
				List oldList = rows[i-1];
				System.out.println(oldList);
				Entry val = new Entry(j, x);
				//Entry old = null;
				oldList.moveFront();
				if(oldList.index() == -1){
					Entry v = new Entry(j, x);
					oldList.append(v);
					return;
				} 
				//System.out.println("list index is "+oldList.index()+" "+oldList.length());
				for(oldList.moveFront() ; oldList.index() > -1; oldList.moveNext()){
					Object p = oldList.get();
					//System.out.println("");
					Entry old =(Entry)p;
					if(old.column == j){
						old.value = x; 
						NNZ++;
						return;
					}
					if(old.column > j){
						oldList.insertBefore(val);
						return;
					}
				}
				oldList.append(val);
				NNZ++;
		}
	}
	
		/*	//v.delete(); set Entry = null before inserting
			v.delete();
			v.append(new Entry(j, x));
			//z.clear();
			//v.append(j, newValfFinal);
		}
	}*/

	// returns a new Matrix that is the scalar product of this Matrix with x
	public Matrix scalarMult(double x){
		if( x == 0){
			this.makeZero();
		}

		Matrix mult = new Matrix(rows.length);
		for(int c = 0; c < rows.length; c++){
			List oldMat =  rows[c];
			List newMat = mult.rows[c];
			for(oldMat.moveFront(); oldMat.index() >= 0; oldMat.moveNext()){
				Entry p = (Entry) oldMat.get();
				//System.out.print("this is  " + p.value);
				//Double z = (p.value * x);
				Entry v2 = new Entry(p.column, (p.value)*x);
				newMat.append(v2);
			}
		}
		mult.NNZ = NNZ;
		return mult;
	}

	public Matrix add (Matrix M){
		if(getSize() == M.getSize()){
			if(M == this){
				return this.scalarMult(2);
			}

			Matrix cop = new Matrix(rows.length);

			for (int i = 0; i<rows.length; i++){
				List m1 = rows[i];
				List m2 = M.rows[i];
				List copList = cop.rows[i];
				m1.moveFront();
				m2.moveFront();
				while(m1.index() >= 0 && m2.index() >=  0){
					Entry ent1 = (Entry)m1.get();
					Entry ent2 = (Entry)m2.get();
					Entry sum = (new Entry(ent1.column, ent1.value + ent2.value));
					//Entry sum = sum.changeEntry(i, ent1.column, ent1.value + ent2.value);
					cop.NNZ++;
					if(ent1.column == ent2.column){
						if(ent1.value + ent2.value ==0){
							NNZ--;
						}else{
							copList.append(sum);
						}
						m1.moveNext();
						m2.moveNext();
					}else if(ent1.column < ent2.column){
						copList.append(new Entry(ent1.column, ent1.value));
						//copList.changeEntry(i, ent1.column, ent1.value);
						m1.moveNext();
					}else{
						copList.append(new Entry(ent2.column, ent2.value));
						//copList.changeEntry(i, ent2.column, ent2.value);
						m2.moveNext();
					}

				}
				
				List endList;
				if(m1.index() >=0){
					endList = m1;
				}else{
					endList = m2;
				}
				while(endList.index() >= 0){
					Entry x=(Entry)endList.get();
					cop.NNZ++;
					copList.append(new Entry(x.column, x.value));
					//copList.changeEntry(i, x.column, x.value);
					endList.moveNext();
				}
			}
			return cop;
		}else{
			System.err.println("StdErr: cannot Add Matrices");
			return null;
		}
	}

	public Matrix sub (Matrix M){
		if(getSize() == M.getSize()){
			if(M == this){
				return this.scalarMult(0);
			}

			Matrix cop = new Matrix(rows.length);

			for (int i = 0; i<rows.length; i++){
				List m1 = rows[i];
				List m2 = M.rows[i];
				List copList = cop.rows[i];
				m1.moveFront();
				m2.moveFront();
				while(m1.index() >= 0 && m2.index() >=  0){
					Entry ent1 = (Entry)m1.get();
					Entry ent2 = (Entry)m2.get();
					Entry sub = (new Entry(ent1.column, ent1.value - ent2.value));
					cop.NNZ++;
					if(ent1.column == ent2.column){
						if(ent1.value - ent2.value ==0){
							NNZ--;
						}else{
							copList.append(sub);
						}
						m1.moveNext();
						m2.moveNext();
					}else if(ent1.column < ent2.column){
						copList.append(new Entry(ent1.column, ent1.value));
						m1.moveNext();
					}else{
						copList.append(new Entry(ent2.column, 0-ent2.value));
						m2.moveNext();
					}

				}
				
				List endList;
				if(m1.index() >=0){
					endList = m1;
				}else{
					endList = m2;
				}

				while(endList.index() >= 0){
					Entry x=(Entry)endList.get();
					cop.NNZ++;
					if(m1.index() >= 0){
						copList.append(new Entry(x.column, x.value));
						endList.moveNext();
					}else if(m2.index() >= 0){
						copList.append(new Entry(x.column, (-1 * x.value)));
						endList.moveNext();
					}
				}
			}
			return cop;
		}else{
			System.err.println("StdErr: cannot Subtract Matrices");
			return null;
		}
	}
	
	public static double dot(List P, List Q){
		double pq = 0;
		if(P.length() != Q.length()){
			System.out.print(" Not n*x matrices-incompatible");
			return 0;
		}
		while(P.length() >= 0 && Q.length() >= 0){
			Entry p = (Entry)(P.get());
			Entry q = (Entry)(Q.get());
			if(P.index() == Q.index()){
				pq += p.value * q.value;
				P.moveNext();
				Q.moveNext();
			}else if(p.column < q.column){
				P.moveNext();
			}else{
				Q.moveNext();
			}
		}
		return pq;
	}



	Matrix transpose(){
		Matrix T = new Matrix(rows.length);
		for(int i = 0; i<rows.length; i++){
			List A = rows[i];
			for(A.moveFront(); A.index() >= 0; A.moveNext()){
				Entry entry = (Entry)A.get(); 
				int j = entry.column-1;
					T.changeEntry(j, i+1, entry.value);
			}
		}
		return T;
	}
 
 //    public Matrix transpose(){
 //    	Matrix copy = new Matrix(rows.length);
	// // iterates over current matrix rows
 //    	for(int i = 0; i < rows.length; i++){
 //    		List row = rows[i];
 //    		for(row.moveFront(); row.index() >= 0; row.moveNext()){
 //    			Entry entry = (Entry)(row.get());
	// 	// converts column indexes into row indexes
 //    			int k = entry.column - 1;
 //    			copy.rows[k].append(new Entry(i + 1, entry.value));
 //    		}
 //    	}
 //    	copy.NNZ = NNZ;
 //    	return copy;
 //    }

	// Matrix mult(Matrix M){
		// if(rows.length != M.rows.length){
		// 	System.err.println("StdErr: Incompatible Matrices");
		// 	return null;
		// }
	// 	Matrix cop = new Matrix(rows.length);
		
	// 	Matrix t = M.transpose();

	// 	for(int i = 0; i < rows.length; i++){
	// 		if(rows[i].length() == 0){
	// 			continue;
	// 		}

	// 	for(int k = 0; k < rows.length; k++){
	// 		if(t.rows[k].length() == 0){
	// 			continue;
	// 		}
	// 		double x = dot(rows[i], t.rows[k]);
	// 		if(x != 0){
	// 			Entry v = new Entry(k+1, x);
	// 			cop.rows[i].append(v);
	// 			cop.NNZ++;
	// 		}
	// 	}
	// 	}
	// 	return cop;
	// }
	public Matrix mult(Matrix x){
			if(rows.length != x.rows.length){
			System.err.println("StdErr: Incompatible Matrices");
			return null;
		}

		Matrix cop = new Matrix(rows.length);
		if(NNZ == 0 || x.NNZ == 0) return cop;
		Matrix trans = x.transpose();
		for(int i = 0; i < rows.length; i++){
	    // if the list length is 0 skip
			if(rows[i].length() == 0) continue;
			for(int j = 0; j < rows.length; j++){
				if(trans.rows[j].length() == 0) continue;
				double ij = dot(rows[i] , trans.rows[j]);
				if(ij != 0){
					cop.rows[i].append(new Entry(j + 1, ij));
					cop.NNZ++;
				}
			}
		}
		return cop;

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
	//.add() function requires a helper function 

    

