import java.io.*;
import java.util.*;
import java.math.*;

public class Main{

	private static Scanner in;

	public static BigInteger solve(int cur, int prev, int end, BigInteger[][] dp){
		if(cur == end) return BigInteger.valueOf(1);

		if(dp[cur][prev] != BigInteger.valueOf(-1)) return dp[cur][prev];

		if(prev == 1){
			BigInteger ret = solve(cur + 1, prev, end, dp);

			ret = ret.add(solve(cur + 1, 0, end, dp));

			return dp[cur][prev] = ret;
		}

		return dp[cur][prev] = solve(cur + 1, 1, end, dp);
	}

	public static void main(String args[]) {
		in = new Scanner(System.in);

		int n = in.nextInt();

		BigInteger[][] dp = new BigInteger[n + 1][2];

		for(int i = 0; i < n + 1; ++i){
			dp[i][0] = dp[i][1] = BigInteger.valueOf(-1);
		}

		BigInteger ans = solve(1, 1, n, dp);

		ans = ans.add(solve(1, 0, n, dp));
		
		System.out.println(ans);
	}
}