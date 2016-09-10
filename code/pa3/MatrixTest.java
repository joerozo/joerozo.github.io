class MatrixTest{

	public static void main(String[] args) {

		Matrix m1 = new Matrix(5);
		Matrix m2 = new Matrix (5);
		System.out.println("it compiled!");
		m1.changeEntry(1, 1, 4);
		m1.changeEntry(2, 3, 7);

		m1.changeEntry(2,2,3);

		// changeEntry works :)

		System.out.printf("m is a %d x %d matrix ", m1.getSize(), m1.getSize());
		System.out.printf("with %d non-zero elements\n", m1.getNNZ());

		// getSize() and getNNZ() work

		System.out.println("m:");
		System.out.println(m1);

		// toString() works
		Matrix C = m1.scalarMult(2.5);
		System.out.println(C.getNNZ());
		System.out.println(C);

		Matrix c2 = m1.add(m1);
		System.out.println(c2.getNNZ());
		System.out.println(c2);


		Matrix c3 = c2.sub(m1);
		System.out.println(c3.getNNZ());
		System.out.println(c3);

		Matrix F = m1.transpose();
		System.out.println(F.getNNZ());
		System.out.println(F);

		Matrix G = m1.mult(m1);
		System.out.println(G.getNNZ());
		System.out.println(G);

		m1.makeZero();

		System.out.println(m1);

		Matrix n = m1.copy();
		n.changeEntry(4, 4, -99);
		n.changeEntry(4, 5, 101);
		System.out.println("n:");
		System.out.println(n);

		// copy works and multiple entries in the same row work

		

	}
}