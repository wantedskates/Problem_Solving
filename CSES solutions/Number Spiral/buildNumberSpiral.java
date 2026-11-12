import java.util.Scanner;
public class buildNumberSpiral {

    static Scanner scanner = new Scanner(System.in);
    static void work(){



            int r = scanner.nextInt();

            int [ ][ ] G = new int[r][r];

            // F is the filler value that fills cells of the grid
            int x = 0 , y=0 , F = 1;


            for (int i =1; i<= r-1; i++ ){

                if (i==1){
                    G[x][y] = F;
                }



                // Down_Left loop ( call it DL)
                if ((i % 2) != 0){

                    // Transitioning from the RU loop to the DL loop

                    {
                        y++;
                        G[x][y] = ++F;

                    }

                    //Downward movement
                    for (int j =0; j<i; j++){
                        x++;
                        G[x][y] = ++F;

                    }

                    //Leftward movement
                    for (int j =0; j<i; j++){
                        y--;
                        G[x][y] = ++F;
                    }


                    // Transitioning from the DL loop to the RU loop
                    x++;
                    G[x][y] = ++F;



                }
                else
                // Right_Up loop (call it RU)
                {

                    //Rightward movement
                    for (int j =0; j<i; j++){
                        y++;
                        G[x][y] = ++F;
                    }

                    //Upward movement
                    for (int j =0; j<i; j++){
                        x--;
                        G[x][y] = ++F;
                    }








                }









            }

            for (int [] iArr : G){
                for (int i : iArr){
                    System.out.printf("%2d " , i);
                }

                System.out.print("\n");
            }









    }

    public static void main(String[] args){
        buildNumberSpiral.work();
    }
}
