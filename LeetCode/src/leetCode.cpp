#include "leetCode.h"
#include "data.h"

namespace leetcode
{
    /**
     * **********************************************************************************
     *                       @brief Problems of Easy Levels                             *
     * **********************************************************************************
     */

    /**
     * @brief Solving the problems of addBinary
     *
     */
    string LeetCodeProblems::addBinary(string a, string b)
    {
        int m = a.length() - 1, n = b.length() - 1, carry = 0;
        string res = "";

        while ((m >= 0 || n >= 0) || carry)
        {
            int d1 = (m >= 0) ? a[m--] - '0' : 0;
            int d2 = (n >= 0) ? b[n--] - '0' : 0;
            int sum = d1 + d2 + carry;

            if (sum == 2)
            { // case of 1 1 0 or 1 0 1 or 0 1 1
                sum = 0;
                carry = 1;
            }
            else if (sum == 3)
            { // case  when a[i]=1,b[i]=1, carry=1;
                sum = 1;
                carry = 1;
            }
            else
                carry = 0;
            res.insert(0, to_string(sum));
        }

        return res;
    }

    /**
     * @brief Solving the problems of longestCommonPrefix
     *
     * Algorithm:
     *
     * from above example we can see:
     * taking the first element is standard:
     * strs[0] ------ f ------- l ------- o
     * checking:
     * strs[1] ------ ^ ------- ^ ------- ^
     * strs[2] ------ ^ ------- ^ ------- x -> resturn res
     * --------------------------------------
     * res =          f        fl        return
     *
     *
     */
    string LeetCodeProblems::longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 1)
            return strs[0];

        string res = "";
        int size = strs.size();
        int len = strs[0].length();

        for (int i = 0; i < len; i++)
        {
            char c = strs[0][i];
            for (int j = 1; j < size; j++)
            {
                if (strs[j][i] != c)
                {
                    return res;
                }
            }
            res += c;
        }
        return res;
    }

    /**
     * @brief Solving the problems of twoSum
     *
     */
    vector<int> LeetCodeProblems::twoSum(vector<int> &nums, int target)
    {
        vector<int> res;

        int len = nums.size();

        for (int index = 0; index < len; index++)
        {
            // target = num_1 + num_2 => num_2 = target - num_1
            int num_2 = target - nums[index];
            int start = index + 1;
            while (start < len)
            {
                if (nums[start] == num_2)
                {
                    res.push_back(index);
                    res.push_back(start);
                    return res;
                }
                start++;
            }
        }
        return res;
    }

    int LeetCodeProblems::strStr(string haystack, string needle)
    {
        int _lengthOfStack = haystack.length();
        int _lengthOfNeedle = needle.length();
        if (_lengthOfStack == 0 && _lengthOfNeedle == 0)
            return 0;

        for (int index = 0; index < _lengthOfStack; index++)
        {
            string temp = haystack.substr(index, _lengthOfNeedle);
            if (temp == needle)
                return index;
        }

        return -1;
    }

    /**
     * @brief Solving the problems of postorderTraversel
     *
     *
     */
    vector<int> LeetCodeProblems::postorderTraversal(TreeNode *root)
    {
        vector<int> res{};
        if (root == NULL)
            return res;
        else
        {
            vector<int> temp = postorderTraversal(root->left);
            std::copy(temp.begin(), temp.end(), std::back_inserter(res));

            temp = postorderTraversal(root->right);
            std::copy(temp.begin(), temp.end(), std::back_inserter(res));

            res.push_back(root->val);
        }
        return res;
    }

    /**
     * @brief Solving the problems of removeDuplicates
     *
     * @param nums
     * @return int
     */
    int LeetCodeProblems::removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 1;
        vector<int>::iterator ip;
        ip = std::unique(nums.begin(), nums.end());
        // Resizing the vector so as to remove the undefined terms
        nums.resize(std::distance(nums.begin(), ip));

        return nums.size();
    }

    /**
     * @brief Solving the problems of searchInsert
     *
     * @param nums
     * @param target
     * @return int
     */
    int LeetCodeProblems::searchInsert(vector<int> &nums, int target)
    {
        if (target <= nums[0])
            return 0;
        int len = nums.size();
        if (target > nums[len - 1])
            return len;
        if (target == nums[len - 1])
        {
            return len - 1;
        }
        return findPos(nums, target);
    }

    int LeetCodeProblems::findPos(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size();
        int middle = (start + end) / 2;
        while (!(nums[middle] == target || (nums[middle] > target && nums[middle - 1] < target) || (nums[middle] < target && target < nums[middle + 1])))
        {
            middle = (start + end) / 2;

            if (nums[middle] < target)
                start = middle;
            if (nums[middle] > target)
                end = middle;
        }

        if (nums[middle] == target || (nums[middle] > target && nums[middle - 1] < target))
            return middle;
        if (nums[middle] < target && target < nums[middle + 1])
            return middle + 1;

        return middle;
    }

    /**
     * @brief Solving the problems of singleNumber
     *
     */
    int LeetCodeProblems::singleNumber(vector<int> &nums)
    {
        int res = {0};
        for (int i : nums)
        {
            res ^= i;
        }
        return res;
    }

    /**
     * @brief Solving the problems of deleteDuplicates
     *
     */
    ListNode *LeetCodeProblems::deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        ListNode *currList = head;
        ListNode *nextList = nullptr;

        if (head->next != nullptr)
            nextList = head->next;

        while (nextList != nullptr)
        {
            if (currList->val != nextList->val)
            {
                currList = nextList;
                nextList = nextList->next;
            }
            else
            {
                currList->next = nextList->next;
                ListNode *temp = nextList;
                nextList = currList->next;

                delete temp;
                temp = nullptr;
            }
        }

        currList = nullptr;
        nextList = nullptr;

        return head;
    }

    /**
     * @brief Solving the problems of merge
     *
     */
    void LeetCodeProblems::merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // Don't you this way -> because you don't know the algorithm - even though this solution is very fast
        std::merge(nums2.rbegin() + (nums2.size() - n),
                   nums2.rend(),
                   nums1.rbegin() + (nums1.size() - m),
                   nums1.rend(), nums1.rbegin(),
                   [](const int l, const int r)
                   { return l >= r; });
    }

    int LeetCodeProblems::titleToNumber(string columnTitle)
    {
        int _size = columnTitle.length();
        int _res = 0;
        for (int i = 0; i < _size; i++)
        {
            if (i != 0)
            {

                _res = (_res * 26) + ((int)columnTitle[i] - 64);
            }
            else
            {
                _res += (int)columnTitle[i] - 64;
            }
        }
        return _res;
    }

    /**
     * @brief
     */
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    /**
     * **********************************************************************************
     *                       @brief Problems of Medium Levels                           *
     * **********************************************************************************
     */

    /**
     * @brief Solving the problems of isValid
     *
     */
    bool LeetCodeProblems::isValid(string s)
    {
        if (s.length() == 1)
            return false;
        if (s[0] == '}' || s[0] == ']' || s[0] == ')')
            return false;

        stack<char> check;
        map<char, char> brackets{
            {')', '('},
            {'}', '{'},
            {']', '['}};

        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
                check.push(c);
            else
            {
                if (check.empty())
                    return false;
                if (check.top() == brackets[c])
                    check.pop();
                else
                    return false;
            }
        }
        return check.size() == 0 ? true : false;
    }

    /**
     * @brief Solving the problems of combinationSum
     */
    vector<vector<int>> LeetCodeProblems::combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        int _numberOfCadidates = candidates.size();
        for (int i = 0; i < _numberOfCadidates; i++)
        {
            vector<Combination> stack;
            struct Combination com;

            // check single value
            if (candidates[i] == target)
            {
                vector<int> okay;
                okay.push_back(candidates[i]);
                res.push_back(okay);
                continue;
            }

            // push i vao stack
            com.arr.push_back(candidates[i]);
            com.sum += candidates[i];
            com.idx = i;
            stack.push_back(com);

            // duyet stack
            while (stack.size() != 0)
            {
                // lay ra phan tu cuoi cung
                struct Combination temp;
                temp = stack[stack.size() - 1];
                stack.pop_back();
                int _numOfCandidate = candidates.size();
                for (int j = temp.idx; j < _numOfCandidate; j++)
                {
                    struct Combination temp2;
                    temp2 = temp;
                    if (temp.sum + candidates[j] <= target)
                    {
                        temp2.arr.push_back(candidates[j]);
                        temp2.sum += candidates[j];
                        temp2.idx = j;
                        stack.push_back(temp2);
                        if (temp.sum + candidates[j] == target)
                        {
                            res.push_back(temp2.arr);
                            stack.pop_back();
                        }
                    }
                }
            }
        }
        return res;
    }

    /**
     * @brief Solving the problems of intToRoman
     */
    string LeetCodeProblems::intToRoman(int num)
    {
        map<int, string> romanList{
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}};
        string res = "";
        int arr[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int i = 0;
        while (num > 0)
        {
            if (num < arr[i])
            {
                i++;
                continue;
            }
            else
            {
                int temp = num / arr[i];
                // adding numbers of words
                for (int j = 0; j < temp; j++)
                {
                    res += romanList[arr[i]];
                }
                num = num % arr[i];
                i++;
            }
        }

        return res;
    }

    /**
     * @brief Solving the problems of myAtoi
     */
    int LeetCodeProblems::myAtoi(string s)
    {
        const int n = s.length();
        // 1.passing leading space
        int start = 0;
        while (start < n && s[start] == ' ')
        {
            start++;
        }
        if (start == n)
            return 0;
        // 2. sign
        bool positive = true;
        if (s[start] == '-' || s[start] == '+')
        {
            positive = s[start] == '+';
            start++;
        }
        // 3. convert string to number
        if (!isdigit(s[start]))
            return 0;
        int ans = 0;
        int max_unit = INT_MAX % 10;
        int min_unit = INT_MIN % 10;
        while (start < n && isdigit(s[start]))
        {
            int unit = (s[start++] - '0');
            if (!positive)
            {
                unit = -unit;
            }
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && unit > max_unit))
                return INT_MAX;
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && unit < min_unit))
                return INT_MIN;
            ans = ans * 10 + unit;
        }

        return ans;

        /*  //  Second way
        {
            int i = 0;
            while(s[i] == ' ') ++i;
            int sig = 1;
            if(s[i] == '-')
            {
                sig = -1;
                ++i;
            }
            else if(s[i] == '+')
            {
                ++i;
            }
            if(s[i] < '0' || s[i] > '9') return 0;
            ll ans = 0;
            while(s[i] >= '0' && s[i] <= '9' && i < s.size())
            {
                ans *= 10;
                ans += (s[i++] - '0');
                if(ans*sig >= INT_MAX) return INT_MAX;
                if(ans*sig <= INT_MIN) return INT_MIN;
            }
            return (int) ans*sig;
        }
        */
    }

    /**
     * @brief Solving the problems of longestPalindrome
     *
     */
    string LeetCodeProblems::longestPalindrome(string s)
    {
        string ans = "";
        int len = 0, maxLen = 0, idx = 0;
        int _sizeOfString = s.size();
        for (int i = 0; i < _sizeOfString; ++i)
        {
            int left = i - 1, right = i + 1;
            len = pallindromeLength(left, right, s);
            idx = (len > maxLen) ? left : idx;
            maxLen = max(len, maxLen);

            left = i;
            right = i + 1;
            len = pallindromeLength(left, right, s);
            idx = (len > maxLen) ? left : idx;
            maxLen = max(len, maxLen);
        }

        if (maxLen)
            ans = s.substr(idx, maxLen);
        return ans;
    }

    /**
     * @brief Supporting function -> finding out the pallindrome string
     *
     */
    int LeetCodeProblems::pallindromeLength(int &l, int &r, string &s)
    {
        int _sizeOfStr = s.size();
        while (l >= 0 && r < _sizeOfStr && s[l] == s[r])
        {
            l--;
            r++;
        }
        l++;
        r--;
        return (r - l + 1);
    }

    int LeetCodeProblems::lengthOfLongestSubstring(string s)
    {
        int n = s.size(), result = 0;
        // creating hashmap for storing unique character and their index
        map<char, int> sm;
        int start = 0, end = 0;
        for (end = 0; end < n; end++)
        {

            if (sm.find(s[end]) != sm.end()) // if element is present in map then we have to find the previous substring size
            {
                // Update the result for the substring in the current window before we found duplicate character
                result = max(result, end - start);
                int duplicateIndex = sm[s[end]];
                //  Remove all characters before the new
                for (int i = start; i <= duplicateIndex; i++)
                {
                    sm.erase(s[i]);
                }
                // Slide the window since we have found a duplicate character
                start = duplicateIndex + 1;
            }
            // Add the current character to hashmap
            sm[s[end]] = end;
        }

        return max(result, n - start);
    }

    int LeetCodeProblems::findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> map;
        int _max = INT_MIN;
        int _sum = 0;
        int _idex = 0;
        for (auto elems : nums)
        {
            _sum += elems == 0 ? -1 : 1;

            if (_sum == 0)
            {
                _max = _idex + 1;
            }
            else
            {
                if (map.find(_sum) == map.end())
                {
                    map[_sum] = _idex;
                }
                else
                {
                    _max = max(_max, _idex - map[_sum]);
                }
            }

            _idex++;
        }

        return _max == INT_MIN ? 0 : _max;
    }

    /**
     * @brief
     *
     * @param nums
     * @return vector<vector<int>>
     */
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        const size_t len = nums.size();
        if (len < 3)
            return {};

        std::sort(nums.begin(), nums.end());

        std::set<vector<int>> unique_results;

        for (int i = 0; i < len - 2; i++)
        {

            int j = i + 1;
            int k = len - 1;

            while (j < k)
            {
                const int sum = nums[i] + nums[j] + nums[k];
                if (0 == sum)
                {
                    unique_results.insert({nums[i], nums[j++], nums[k--]});
                }
                else if (0 > sum)
                    j++;
                else if (0 < sum)
                    k--;
            }
        }

        vector<vector<int>> results;

        std::copy(
            unique_results.begin(), unique_results.end(),
            std::back_inserter(results));

        return results;
    }

    /**
     * @brief
     *
     * @param nums
     * @param target
     * @return vector<vector<int>>
     */
    vector<vector<int>> LeetCodeProblems::fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> solution;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    int x = (long long)target - (long long)nums[j] - (long long)nums[k] - (long long)nums[i];
                    if (binary_search(nums.begin() + k + 1, nums.end(), x))
                    {
                        vector<int> ans{nums[i], nums[j], nums[k], x};

                        int track = 0;
                        for (int m = 0; m < solution.size(); m++)
                        {

                            for (int n = 0; n < ans.size(); n++)
                            {
                                if (solution[m][n] == ans[n])
                                {
                                    track++;
                                }
                            }
                            if (track == ans.size())
                            {
                                break;
                            }
                            track = 0;
                        }

                        if (track != ans.size())
                        {
                            solution.push_back(ans);
                        }
                    }
                }
            }
        }
        return solution;
    }

    // 3 ^ 5 => 3 ^ 2 -> 3 ^ 1 => 3 ^ 0
    // 9 * 9 * 3
    /**
     * @brief
     */
    double LeetCodeProblems::myPow(double x, int n)
    {
        if (n == -1)
            return 1 / x;
        if (n == 0)
            return 1;

        double tmp = myPow(x, n / 2);

        if (n % 2 == 0)
        {
            return tmp * tmp;
        }

        if (n < 0)
            return tmp * tmp * (1 / x);

        return tmp * tmp * x;
    }

    /**
     * **********************************************************************************
     *                       @brief Problems of Hard Levels                             *
     * **********************************************************************************
     */

    double LeetCodeProblems::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        /*  Frist way */
        const int m = nums1.size();
        const int n = nums2.size();
        bool isEven = (m + n) % 2 == 0 ? true : false;
        int medianPos = isEven ? (m + n - 1) / 2 : (m + n) / 2;
        double _result = 0;
        vector<int> _res;
        vector<int>::iterator _itrNums1 = nums1.begin();
        vector<int>::iterator _itrNums2 = nums2.begin();

        while (_itrNums1 != nums1.end() && _itrNums2 != nums2.end())
        {
            if (*_itrNums1 < *_itrNums2)
            {
                _res.push_back(*_itrNums1);
                _itrNums1++;
            }
            else
            {
                _res.push_back(*_itrNums2);
                _itrNums2++;
            }
        }

        // pushing the rest of elems in vector1
        while (_itrNums1 != nums1.end())
        {
            _res.push_back(*_itrNums1);
            _itrNums1++;
        }

        // pushing the rest of elems in vector2
        while (_itrNums2 != nums2.end())
        {
            _res.push_back(*_itrNums2);
            _itrNums2++;
        }

        _result = isEven ? (_res[medianPos + 1] + _res[medianPos]) / 2.0 : _res[medianPos] / 1.0;
        return _result;
    }
};