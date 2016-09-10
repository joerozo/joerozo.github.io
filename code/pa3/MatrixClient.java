public class MatrixClient{
   public static void main(String[] args){
      int i, j, n=10;
      Matrix A = new Matrix(n);
      Matrix B = new Matrix(n);
      
      System.out.println(A.getNNZ());
      
      A.changeEntry(1,1,1); B.changeEntry(1,1,1);

      A.changeEntry(1,2,2); B.changeEntry(1,2,0);
      A.changeEntry(1,3,3); B.changeEntry(1,3,1);
      A.changeEntry(2,1,4); B.changeEntry(2,1,0);
      A.changeEntry(2,2,5); B.changeEntry(2,2,1);
      A.changeEntry(2,3,6); B.changeEntry(2,3,0);
      A.changeEntry(3,1,7); B.changeEntry(3,1,1);
      A.changeEntry(3,2,8); B.changeEntry(3,2,1);

      A.changeEntry(3,3,9); B.changeEntry(3,3,1);

      System.out.println(A.getNNZ());
      System.out.print("This is A: ");
      System.out.println(A); 
      //Matrix F = A.transpose();
      //System.out.print("this is A transpose");
      //System.out.print(F);
      System.out.println(B.getNNZ()); 
      System.out.print("This is B: ");
      System.out.println(B);
      
      Matrix C = B.scalarMult(1.5);
      System.out.println(C.getNNZ());

      System.out.println(C);

      //System.out.print("THIS IS ADD");
      Matrix D = B.add(A);
      System.out.println(D.getNNZ());
      
      System.out.println(D);

      Matrix E = B.sub(A);
      System.out.println(E.getNNZ());
      System.out.println("Subtract");
      System.out.println(E);

      Matrix F = B.transpose();
      System.out.println(F.getNNZ());
      System.out.print("This is B Transpose: ");
      System.out.println(F);

      Matrix G = B.mult(B);
      System.out.println(G.getNNZ());
      System.out.println(G);

      Matrix H = A.copy();
      System.out.println(H.getNNZ());
      System.out.println(H);
      System.out.println(A.equals(H));
      System.out.println(A.equals(B));
      System.out.println(A.equals(A));

      A.makeZero();
      System.out.println(A.getNNZ());
      System.out.println(A);
   }
}