#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
//LeetCode 75.颜色分类 选择排序
//https://leetcode.cn/problems/sort-colors/

// LeetCode 88.合并两个有序数组
// https://leetcode.cn/problems/merge-sorted-array/

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};
class SortClass {
public:
	//1.选择排序：选择当前下标值和找到的最小的下标值交换位置
	void SelectSort1(vector<int>& v) {
		int n = v.size();
		for (int i = 0;i < n;++i) {
			int min = i;
			for (int j = i;j < n;++j) {
				if (v[j] < v[min]) {
					min = j;
				}
			}
			int tmp = v[min];
			v[min] = v[i];
			v[i] = tmp;
		}
	}
	//2.冒泡排序：比较二次循环内的大小，依次寻找某个下标值的适当的位置
	void BubbleSort(vector <int>& v) {
		int n = v.size();
		for (int i = n-1; i >= 0;--i) {
			for (int j = 0;j < i;++j) {
				if (v[j] > v[j + 1]) {
					int tmp = v[j];
					v[j] = v[j + 1];
					v[j + 1] = tmp;
				}
			}
		}
	}
	//3.插入排序：拿一个下标值依次从后往前比较，然后对比的数值往后挪，当前数值插入进去
	void InsertSort(vector <int>& a) {
		for (int i = 1;i < a.size();++i) {
			int x = a[i];
			int j;
			for (j = i - 1;j >= 0;--j) {
				if (x < a[j]) {
					a[j + 1] = a[j];
				}
				else {
					break;
				}
			}
			a[j + 1] = x;
		}
	}
	//4.计数排序
	void CountingSort(vector <int>& v, int m) {
		int min = v[0];
		int max = v[0];

		//来减少时间
		//int min = *std::min_element(v.begin(), v.end());
		//int max = *std::max_element(v.begin(), v.end());
		int n = v.size();
		for (int i = 0;i < n;++i) {
			if (v[i] < min) min = v[i];
			if (v[i] > max) max = v[i];
		}
		int range = max - min;

		
		int* count = new int[range + 1];
		memset(count, 0, sizeof(int) * (range + 1));

		for (int i = 0;i < n;++i) {
			count[v[i] - min]++;
		}
		int idx = 0;
		for (int i = 0;i <= range; ++i) {
			while (count[i] > 0) {
				v[idx++] = i + min;
				count[i]--;
			}
		}
		delete[] count;
	}
	//5.1归并排序：时间复杂度为O(nlogn)
	void Merge(vector <int>& v, int l, int m, int r) {
		int n1 = m - l + 1;//左半部分缺少的元素个数需要加1
		int n2 = r - m;//右半部分r-m个元素，就是m+1到r的元素个数
		int len = r - l + 1;
		vector <int> tmp(len);
		for (int i = 0;i < n1; ++i) {
			tmp[i] = v[l + i];
		}
		for (int j = 0;j < n2;j++) {
			tmp[j + n1] = v[j + m + 1];
		}
		int i = 0, j = n1, k = l;
		while (i < n1 && j < len) {
			if (tmp[i] <= tmp[j]) {
				v[k++] = tmp[i++];
			}
			else {
				v[k++] = tmp[j++];
			}
		}
		while (i < n1) {
			v[k++] = tmp[i++];
		}
		while (j < len) {
			v[k++] = tmp[j++];
		}
	}
	void MergeSort(vector <int>& v, int l, int r) {
		if (l >= r) return;

		int m = (l + r) / 2;
		MergeSort(v, l, m);
		MergeSort(v, m+1, r);
		if (v[m] <= v[m + 1]) return;
		Merge(v, l, m, r);
	}
	//5.2归并排序优化
	//void MergeSort2(vector <int>& v, int l, int r) {
	//	if (l >= r) return;
	//	int m = (l + r) / 2;
	//	MergeSort2(v, l, m);
	//	MergeSort2(v, m + 1, r);
	//	if (v[m] <= v[m + 1]) return; //如果已经有序就不需要合并了
	//	Merge(v, l, m, r);
	//}
	//5.3归并排序双指针链表
	ListNode* MergeNodeList(ListNode* left, ListNode* right) {
		ListNode* dummy = new ListNode(0); //虚拟结点
		ListNode* tmp = dummy;
		while (left != nullptr && right != nullptr) {
			if (left->val <= right->val) {
				tmp->next = left;
				left = left->next;
			}
			else {
				tmp->next = right;
				right = right->next;
			}
			tmp = tmp->next;
		}
		if (left != nullptr) {
			tmp->next = left;
		}
		else {
			tmp->next = right;
		}
		return dummy->next;
	}
	ListNode* MergeSortNodeList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode* slow = head;
		ListNode* fast = head->next;
		while (fast->next != nullptr && fast->next->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* mid = slow->next;
		slow->next = nullptr; //断开链表
		ListNode* left = MergeSortNodeList(head);
		ListNode* right = MergeSortNodeList(mid);
		return MergeNodeList(left, right);
	}
	//6.快速排序：平均时间复杂度为O(nlogn)，O(n^2)最坏情况 空间复杂度：O(logn)
	int partation(vector<int>& v, int l, int r) {
		int idx = l + rand() % (r - l + 1);
		swap(v[l], v[idx]);
		int i = l, j = r;
		int x = v[idx];
		while (i < j) {
			while (i<j && v[j] > x) {
				--j;
			}
			if (i < j) {
				swap(v[i], v[j]);
				++i;
			}
			while (i < j && v[i] < x) {
				++i;
			}
			if (i < j) {
				swap(v[i], v[j]);
				--j;
			}
		}
		return i;
	}
	void QuickSort(vector<int>& v, int l, int r) {
		if (l >= r) return;

		int pivox = partation(v, l, r);
		QuickSort(v, l, pivox - 1);
		QuickSort(v, pivox + 1, r);
	}
	//7.桶排序
	#define ArrayType char
	vector<vector<ArrayType>> bucket;
	vector<int> count;
	void BucketSort(ArrayType* c, int n, int max) {
		bucket.clear();
		count.resize(max);
		for (int i = 0;i < max; ++i) {
			count[i] = 0;
		}
		for (int i = 0;i < n; ++i) {
			count[c[i]]++;
		}
		for (int i = 0; i <= n; ++i) {
			bucket.push_back({});
		}
		for (int i = 0;i < max; ++i) {
			int cnt = count[i];
			bucket[cnt].push_back(i);
		}
		for (int i = 0;i <= n;++i) {
			sort(bucket[i].begin(), bucket[i].end());
		}
	}
	void PrintBucket(string s) {
		int n = s.size();
		for (int i = n; i > 0; --i) {
			for (int j = 0; j < bucket[i].size(); ++j) {
				for (int k = 0; k < i; ++k) {
					cout << bucket[i][j];
				}
			}
		}
	}
	//8.基数排序
	//使用数组会变成栈溢出，使用new 或 vector方式将内存分配从栈移动到堆上
	void RadixSort(vector<int>& v) {
		int n = v.size();

		const int BASE = 10;
		const int MAXT = 7;
		const int MAXN = 50005;

		int PowOfBase[MAXT];
		PowOfBase[0] = 1;
		for (int i = 1;i < MAXT;++i) {
			PowOfBase[i] = PowOfBase[i - 1] * BASE;
		}

		vector<vector<int>> RadixBucket(BASE, vector<int>(MAXN));
		vector<int> RadixBucketCount(BASE);
		for (int i = 0; i < n; ++i) {
			v[i] += PowOfBase[MAXT - 1];
		}

		int pos = 0;
		while (pos < MAXT) {
			fill(RadixBucketCount.begin(), RadixBucketCount.end(), 0);
			for (int i = 0; i < n; ++i) {
				int idx = v[i] / PowOfBase[pos] % BASE;
				RadixBucket[idx][RadixBucketCount[idx]++] = v[i];
			}
			int top = 0;
			for (int i = 0; i < BASE; ++i) {
				for (int j = 0; j < RadixBucketCount[i]; ++j) {
					v[top++] = RadixBucket[i][j];
				}
			}
			pos++;
		}
		for (int i = 0; i < n; ++i) {
			v[i] -= PowOfBase[MAXT - 1];
		}
	}
	//9.堆排序
	//二叉树父结点数组下标，parent(id) = (id-1)/2
	//二叉树求子结点下标，left(id) = id * 2 +1 ， right(id) = id * 2 +2
	#define idType int
	#define eleType int
	idType lson(idType idx) {
		return idx * 2 + 1;
	}
	idType rson(idType idx) {
		return idx * 2 + 2;
	}
	idType parent(idType idx) {
		return (idx - 1) / 2;
	}
	bool better(eleType a, eleType b) {
		return a > b;
	}
	void Heapify(vector<eleType>& heap, int size, idType curr) {
		idType lsonId = lson(curr);
		idType rsonId = rson(curr);
		idType optId = curr;

		if (lsonId < size && better(heap[lsonId], heap[optId])) {
			curr = lsonId;
		}
		if (rsonId < size && better(heap[rsonId], heap[optId])) {
			curr = rsonId;
		}
		if (curr != optId) {
			swap(heap[optId], heap[curr]);
			Heapify(heap, size, optId);
		}
	}
	vector<int> HeapSort(vector<int>& heap) {
		for (int i = heap.size() - 1; i >= 0;--i) {
			Heapify(heap, heap.size(), i);
		}
		for (int i = heap.size() - 1; i >= 0;--i) {
			swap(heap[0], heap[i]);
			Heapify(heap, i, 0);
		}
		return heap;
	}
	void PrintVector(vector<int>& v) {
		for (vector<int>::iterator iter = v.begin(); iter != v.end();iter++) {
			cout << *iter << " ";
		}
		cout << endl;
	}
};

int main() {
	SortClass S2;
	vector<int> v = { 5,9,15,7,0,3,80,6,2,555,2,284,8,8585,9 };
	S2.HeapSort(v);
	S2.PrintVector(v);

	//桶排序调试
	//string s = "hello world";
	//int n = s.size();
	//S2.BucketSort((char*)s.c_str(), n, 130);
	//S2.PrintBucket(s);
}