import java.util.Scanner;

public class MultiplicationTable {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long n = in.nextLong();

        long low = 1, high = n*n;

        long need = ((n*n) + 1)/2;
        long ans = Long.MAX_VALUE;
        while(low <= high){
            long mid = low + (high - low)/2;

            if(f(mid, n) >= need){
                ans = Math.min(ans, mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }

        }

        System.out.println(ans);


        in.close();
    }

    private static long f(long mid, long n) {
        long tot = 0;
        for(long i = 1; i <= n; i++){
            tot += Math.min(n, mid/i);
        }   

        return tot;
        
    }

    
}
