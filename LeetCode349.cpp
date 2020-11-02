#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1, set2;
        for (auto& num : nums1)
        {
            set1.insert(num);
        }
        for (auto& num : nums2)
        {
            set2.insert(num);
        }
        return getResult(set1,set2);
    }

    vector<int> getResult(unordered_set<int>& set1, unordered_set<int>& set2)
    {
        if (set1.size() > set2.size())
            return getResult(set2, set1);
        vector<int> result;
        for (auto& num : set1){
            if (set2.count(num)){
                result.push_back(num);
            }
        }
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
