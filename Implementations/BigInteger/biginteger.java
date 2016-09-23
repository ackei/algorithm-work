import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args){
		// Example of reading big integers
		/*
		Scanner sc = new Scanner(System.in);
		BigInteger sum = BigInteger.ZERO;
		for (int i = 0; i < 3; i++){
			BigInteger a = sc.nextBigInteger();
			sum = sum.add(a);
		}
		System.out.println(sum);
		*/

		// 25! is too big for longs, but not for BigInteger!
		BigInteger fact_25 = BigInteger.ONE;
		long fact_25_fail = 1;
		for (int i = 2; i <= 25; i++){
			fact_25 = fact_25.multiply(BigInteger.valueOf(i));
			fact_25_fail *= i;
		}
		System.out.println("25! = (BigInteger)" + fact_25); 
		System.out.println("25! = (long)" + fact_25_fail);

		// Also can handle different bases
		String num = "ABCDEF";
		BigInteger big_num = new BigInteger(num,16); //read num as a hexadecimal number
		System.out.println(big_num.toString(10)); // output in decimal
		System.out.println(big_num.toString(16)); // output in hexadecimal
		System.out.println(fact_25.toString(16)); //output in base 16
	}
}
