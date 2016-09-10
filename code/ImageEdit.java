/*********************************************************************/
/* Program: ImageEdit                                      			 */
/* Authors:		Joseph Rozo											 */
/* (Worked with pair programmer Umit Ceylan) 		             	 */							 
/* CMP 12A/L, Winter 2015                                            */
/* Lab assignment 4			                                         */
/* February 20th, 2015                                               */
/*                                                                   */
/* This programs takes in an image file and allows user to			 */
/* manipulate the image rotating it left, right, upside down,        */
/* or mirroring it, and then saving it to a source file.			 */
/*																	 */
/*                                                                   */
/* Input:                                                            */
/* Image File											             */
/*                                                                   */
/* Output:                                                           */
/* Manipulated and saved image.                                      */
/*																	 */
/*********************************************************************/
import java.util.*;
import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.GraphicsConfiguration;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.net.URL;

import javax.imageio.IIOImage;
import javax.imageio.ImageIO;
import javax.imageio.ImageWriteParam;
import javax.imageio.ImageWriter;
import javax.imageio.plugins.jpeg.JPEGImageWriteParam;
import javax.imageio.stream.ImageOutputStream;

    class ImageEdit {

	static File file;			//defines a global variable file//
	static String fname;		//defines a global variable String to store file name//
	
	//main class-throws exception when not functioning properly//
	public static void main(String[] args) throws Exception, IOException {
		BufferedImage img;
		boolean erv=true;	//boolean set to true commences program loop//
		Scanner scan = new Scanner(System.in);	//initialized scanner scans for user input//

		System.out.print("Enter the file name: ");
		String fname = scan.next();	//fname stores user input as the file name//
        
		img = readImage(fname);	//calls readImage method for fileName//
		
		while(erv){	//boolean commences main program loop//
		System.out.print("\n"+"Cmd [ulRLsx]: ");	//prints out command for user to input desired image manipulation//

		String answer = scan.next();	//takes in user desired command l/L/r/u/s/x//
		//loop searching for method which matches user desired command then calling method to manipulate image//
		
		if (answer.equals("R")) {
			System.out.print("rotating right");

			img = rotateR(img);

		}

		else if (answer.equals("u")) {
			System.out.println("flipping up/down");

			img = flippingUpDown(img);

		}

		else if (answer.equals("l")) {
			System.out.print("flipping left/right");

			img = leftRight(img);

		}

		else if (answer.equals("L")) {
			System.out.print("rotating left");

			img = rotateL(img);
			

		}
		//if user selects "s" prompts user for desired jpg saved name then calls save method and saves manipulated image//
		else if(answer.equals("s")){
			System.out.println("saving image");
			System.out.print("filename? ");
			String newName = scan.next();
			
			saveImage(img, new File(newName));
			
		}
		
		//if user selects "x" sets boolean to false terminating program//
		
		else if(answer.equals("x")){
			System.out.println("Bye");
			erv=false;
		}
		}



	}


	//method reads in an image from user fname String//
	public static BufferedImage readImage(String fname) throws Exception {

		BufferedImage image = ImageIO.read(new File(fname));
		return (image);
	}

	//method takes in last manipulated image and stores it under decided name//

	public static void saveImage(BufferedImage img, File file)
			throws IOException {

		ImageWriter writer = null;
		java.util.Iterator iter = ImageIO.getImageWritersByFormatName("jpg");

		if (iter.hasNext()) {
			writer = (ImageWriter) iter.next();
		}

		ImageOutputStream ios = ImageIO.createImageOutputStream(file);
		writer.setOutput(ios);

		ImageWriteParam param = new JPEGImageWriteParam(
				java.util.Locale.getDefault());
		param.setCompressionMode(ImageWriteParam.MODE_EXPLICIT);
		param.setCompressionQuality(0.98f);

		writer.write(null, new IIOImage(img, null, null), param);

	}

	// method takes in w & h of desired image and flips image upside down and returns the manipulated image//
	static BufferedImage flippingUpDown(BufferedImage img) {

		int w = img.getWidth();
		int h = img.getHeight();

		Color pixel;

		BufferedImage updown = new BufferedImage(w, h,
				BufferedImage.TYPE_INT_RGB); 

		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				int color = img.getRGB(i, j);

				updown.setRGB(i, h - j - 1, color);

			}
		}
		return updown;
	}
	//method rotates desired image and returns manipulated image//
	static BufferedImage leftRight(BufferedImage img) {

		int w = img.getWidth();
		int h = img.getHeight();

		Color pixel;

		BufferedImage leftright = new BufferedImage(w, h,
				BufferedImage.TYPE_INT_RGB); // Create it, before the loop

		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				int color = img.getRGB(i, j);

				leftright.setRGB(w - i - 1, j, color);

			}
		}
		return leftright;
	}
	
	//method rotates desired image right and returns manipulated image//
	
	static BufferedImage rotateR(BufferedImage img) {

		int w = img.getWidth();
		int h = img.getHeight();

		Color pixel;

		BufferedImage rotateR = new BufferedImage(h, w,
				BufferedImage.TYPE_INT_RGB); // Create it, before the loop

		for (int i = 0; i < w; i++) { // Now this one is the height
			for (int j = 0; j < h; j++) { // This is the width
				int color = img.getRGB(i, j);

				rotateR.setRGB(h - j - 1, i, color);

			}
		}
		return rotateR;
	}

	//method rotates image left and returns manipulated image//
	
	static BufferedImage rotateL(BufferedImage img) {

		int w = img.getWidth();
		int h = img.getHeight();

		Color pixel;

		BufferedImage rotateL = new BufferedImage(h, w,
				BufferedImage.TYPE_INT_RGB); // Create it, before the loop

		for (int i = 0; i < w; i++) { // Now this one is the height
			for (int j = 0; j < h; j++) { // This is the width
				int color = img.getRGB(i, j);

				rotateL.setRGB(j, w - i - 1, color);

			}
		}
		return rotateL;
	}
}
