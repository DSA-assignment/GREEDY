
package dsa;
import java.util.Scanner; // import the Scanner class 
import java.util.Arrays; 


public class DSA {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        

        // Enter username and press Enter
        System.out.print("Number of Bottles & Number of barrels :"); 
        String[] x = myObj.nextLine().split(" ");   
        System.out.print("Volume of the barrels in bottles :"); 
        String[] y = myObj.nextLine().split(" ");   
        System.out.print("Price of each barrel :"); 
        String[] z = myObj.nextLine().split(" "); 
        int count = z.length;
        int bottles = Integer.parseInt(x[0]);
        double[] p = new double[count];
        for (int i=0 ; i<count ; i++){
            p[i] = Integer.parseInt(z[i])/Integer.parseInt(y[i]);            
        }
        double price_v = 0;
        System.out.println();
        System.out.print("The value is ");
        System.out.println(price( x, y, z, p, bottles, price_v));
        
        
        
    }
    static double price(String[] x, String[] y, String[] z, double[] p, int bottles, double price_v){
        
        double[] maxArray = max(p); //maximum value
        
        if ( Integer.parseInt(y[(int)maxArray[0]]) > bottles ){
            price_v = bottles*p[(int)maxArray[0]];
//            System.out.print("Last ");
//            System.out.println(p[(int)maxArray[0]]);


        }else{
            price_v = Double.parseDouble(y[(int)maxArray[0]])*p[(int)maxArray[0]];
            bottles = bottles - (int)Double.parseDouble(y[(int)maxArray[0]]);
            p[(int)maxArray[0]] = 0;
            price_v = price_v + price( x, y, z, p, bottles, price_v);
        };
        return price_v;
    }
    
    static double[] max(double[] arr){
        double max = 0.0;
        double id = 0;
        for ( int i=0; i< arr.length ; i++ ){
            if ( max < arr[i] ){
                
                id = i;
                max = arr[i];
            };
        };
        double[] array = {id,max};
        return array;
    }
    
}




