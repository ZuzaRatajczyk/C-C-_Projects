
#include <iostream>
#include <vector>
#include <algorithm>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::vector<int> number1;
        std::vector<int> number2;
        std::vector<int> result_num;
        int smaller_size;
        ListNode *current_node1 = l1; 
        ListNode *current_node2 = l2;

        insert_val_into_vector(number1, current_node1);
        insert_val_into_vector(number2, current_node2);

        if(number1.size() < number2.size())
        {
            result_num = add_diff_size_numbers(number1, number2);

        }
        else if(number2.size() < number1.size())
        {
            result_num = add_diff_size_numbers(number2, number1);
        }
        else
        {
            result_num = add_same_size_numbers(number1, number2);
        }

        std::reverse(result_num.begin(), result_num.end());
        ListNode *current_result_node = new ListNode(result_num[0]);
        for (int i = 1; i < result_num.size(); i++)
        {
            current_result_node = new ListNode(result_num[i], current_result_node);
        }

        return current_result_node;
    }

    std::vector<int> add_same_size_numbers(std::vector<int> number1, std::vector<int> number2)
    {
        int remainder = 0;
        std::vector<int> result_num;
        for (int i = 0; i < number1.size(); i++)
        {
            result_num.push_back(number1[i] + number2[i]);
            if (remainder > 0)
            {
                result_num[i] += remainder;
                remainder = 0;
            }
            if (result_num[i] >= 10)
            {

                result_num[i] -= 10;
                remainder = 1;
            }
        }
        if(remainder > 0)
        {
            result_num.push_back(remainder);
            remainder = 0;
        }

        return result_num;
    }

    std::vector<int> add_diff_size_numbers(std::vector<int> smaller_num, std::vector<int> bigger_num)
    {
        int remainder = 0;
        std::vector<int> result_num;
        for (int i = 0; i < smaller_num.size(); i++)
        {
            result_num.push_back(smaller_num[i] + bigger_num[i]);
            if (remainder > 0)
            {
                result_num[i] += remainder;
                remainder = 0;
            }
            if (result_num[i] >= 10)
            {

                result_num[i] -= 10;
                remainder = 1;
            }
        }
        for(int i = smaller_num.size(); i < bigger_num.size(); i++)
        {
            if (remainder > 0)
            {
                result_num.push_back(bigger_num[i] + remainder);
                remainder = 0;
                if (result_num[i] >= 10)
                {

                    result_num[i] -= 10;
                    remainder = 1;
                }
            }
            else
            {
                result_num.push_back(bigger_num[i]);
            }
        }
        if (remainder > 0)
        {
            result_num.push_back(remainder);
            remainder = 0;
        }

        return result_num;
    }

    void insert_val_into_vector(std::vector<int> &vector_of_num, ListNode* node)
    {
        int i = 0;
        do
        {
            std::cout << "Pointer to current element " << node << std::endl;
            vector_of_num.push_back(node->val);
            std::cout << "Element of vector " << vector_of_num[i] << std::endl;
            node = node->next;
            i++;
        } while (node != nullptr);
    }
};


int main()
{
    Solution my_solution;
    ListNode my_node1;
    ListNode my_node2;
    ListNode my_node3;
    ListNode my_node4;
    ListNode my_node5;
    ListNode my_node6;
    ListNode my_node7;
    ListNode my_node8;
    ListNode my_node9;
    ListNode my_node10;
    ListNode my_node11;


    my_node1.val = 9;
    my_node1.next = &my_node2;

    my_node2.val = 9;
    my_node2.next = &my_node3;

    my_node3.val = 9;
    my_node3.next = &my_node4;

    my_node4.val = 9;
    my_node4.next = &my_node5;

    my_node5.val = 9;
    my_node5.next = &my_node6;

    my_node6.val = 9;
    my_node6.next = &my_node7;

    my_node7.val = 9;
    my_node7.next = nullptr;

    my_node8.val = 9;
    my_node8.next = &my_node9;

    my_node9.val = 9;
    my_node9.next = &my_node10;

    my_node10.val = 9;
    my_node10.next = &my_node11;

    my_node11.val = 9;
    my_node11.next = nullptr;

    ListNode* result = my_solution.addTwoNumbers(&my_node1, &my_node8);

    std::vector<int> result_check;
    my_solution.insert_val_into_vector(result_check, result);



    return 0;
}