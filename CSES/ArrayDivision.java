import java.util.*;

public class ArrayDivision {
    public static void main(String[] args) throws Exception {
		//FastIO io = new FastIO("src//input.in","src//output.out");
		Scanner io = new Scanner(System.in);
		long n, k;
		n = io.nextLong(); 
		k = io.nextLong();
		
		long[] v = new long[(int)n+1];
		long[] pre = new long[(int)n+1];
		long sum = 0;

		for(int i = 1; i <= n; i++){
			long x = io.nextInt();
			v[i] = x;
			sum += x;
		}

		pre[0] = 0;

		for(int i = 1; i <= n; i++){
			pre[i] = pre[i-1] + v[i];
		}

		long low = Arrays.stream(v).max().getAsLong();
		long high = sum;
		long ans = -1;

		while(low <= high){
			long mid = low + ((high - low) / 2);
			if(ok(mid, k, pre, n)){
				ans = mid;
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}
		System.out.println(ans);
		io.close();
	}
	static boolean ok(long limit, long k, long[] pre, long n){
		long cnt = 0;
		int i = 1, j = 1;
		while(i <= n && j <= n){
			long curSum = pre[j] - pre[i-1];
			if(curSum <= limit){
				j++;
			}
			else{
				cnt++;
				i = j;
			}
		}
		cnt++;
		if(cnt > k){
			return false;
		}
		else return true;
	}
}
