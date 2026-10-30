#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int timeRequiredToBuy(std::vector<int>& tickets, int k) {
        int total_time = 0;
        int target_tickets = tickets[k];
        
        for (int i = 0; i < tickets.size(); ++i) {
            if (i <= k) {
                total_time += std::min(tickets[i], target_tickets);
            } else {
                total_time += std::min(tickets[i], target_tickets - 1);
            }
        }
        
        return total_time;
    }
};

// Add this main function to fix the linker error locally
int main() {
    Solution solver;
    
    // Example 1 from LeetCode
    std::vector<int> tickets = {2, 3, 2};
    int k = 2;
    
    int result = solver.timeRequiredToBuy(tickets, k);
    
    std::cout << "Total time needed: " << result << " seconds" << std::endl; 
    // Should print: Total time needed: 6 seconds

    return 0;
}
