class Solution {
 public:
    string digits[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string dfs(int n) {
        if (n >= 1000000000) {
            return dfs(n / 1000000000) + " Billion" + dfs(n % 1000000000);
        } else if (n >= 1000000) {
            return dfs(n / 1000000) + " Million" + dfs(n % 1000000);
        } else if (n >= 1000) {
            return dfs(n / 1000) + " Thousand" + dfs(n % 1000);
        } else if (n >= 100) {
            return dfs(n / 100) + " Hundred" + dfs(n % 100);
        } else if (n >= 20) {
            return  " " + tens[n / 10] + dfs(n % 10);
        } else if (n >= 1) {
            return " " + digits[n];
        } else {
            return "";
        }
    }

    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        } else {
            string ret = dfs(num);
            return ret.substr(1, ret.length() - 1);
        }
    }
};