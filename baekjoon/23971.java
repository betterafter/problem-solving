import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
        
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String r = br.readLine();
        String[] readLine = r.split(" ");
        double H = Integer.parseInt(readLine[0]); // y
        double W = Integer.parseInt(readLine[1]); // x
        double N = Integer.parseInt(readLine[2]);
        double M = Integer.parseInt(readLine[3]);
    
        double cntX = Math.ceil(W / (M + 1));
        double cntY = Math.ceil(H / (N + 1));

        System.out.println((int) (cntX * cntY));
    }
}