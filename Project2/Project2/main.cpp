#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

	void num_CPU() {
	std::cout << "Количество аппаратных ядер - " << std::thread::hardware_concurrency() << std::endl;
}

	void sum(std::vector<int>::iterator it_begin1, std::vector<int>::iterator it_end1, std::vector<int>::iterator it_begin2, std::vector<int>::iterator it_end2) {
		std::vector<int> sum;
		std::vector<int>::iterator it1 = it_begin1;
		std::vector<int>::iterator it2 = it_begin2;
		while (it1 <= it_end1 || it2 <= it_end2){
			sum.push_back(*it1 + *it2);
			++it1;
			++it2;
		}
	}


	void thread1(std::vector<int>& v1, std::vector<int>& v2, std::chrono::duration<double>& time) {
		auto start = std::chrono::steady_clock::now();
		std::thread t1(sum, v1.begin(), (v1.end() - 1 ), v2.begin(), (v2.end() - 1));
		t1.join();
		auto end = std::chrono::steady_clock::now();
		time = end - start;
		return;
	}

	void thread2(std::vector<int>& v1, std::vector<int>& v2, std::chrono::duration<double>& time) {
		auto start = std::chrono::steady_clock::now();
		std::thread t1 (sum, v1.begin(), (v1.begin() + (v1.size()/2)), v2.begin(), (v2.begin() + (v2.size() / 2)));
		std::thread t2(sum, (v1.begin() + ((v1.size() / 2) + 1)), (v1.end() - 1), (v2.begin() + ((v2.size() / 2) + 1)), (v2.end() - 1));
		t1.join();
		t2.join();
		auto end = std::chrono::steady_clock::now();
		time = end - start;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		return;
	}

	void thread4(std::vector<int>& v1, std::vector<int>& v2, std::chrono::duration<double>& time) {
		std::vector<int>::iterator arr1[5];
		std::vector<int>::iterator arr2[5];
		arr1[0] = v1.begin();
		arr2[0] = v2.begin();
		size_t n1 = v1.size() / 4;
		size_t n2 = v2.size() / 4;
		for (int i = 0; i < 4; ++i) {
			(arr1[i] + n1) >= v1.end() ? arr1[i+1] = v1.end() - 1 : arr1[i+1] = arr1[i] + n1;
			(arr2[i] + n2) >= v2.end() ? arr2[i+1] = v2.end() - 1 : arr2[i+1] = arr2[i] + n2;
		}
		auto start = std::chrono::steady_clock::now();
		std::thread t1(sum, arr1[0], arr1[1], arr2[0], arr2[1]);
		std::thread t2(sum, arr1[1] + 1, arr1[2], arr2[1] + 1, arr2[2]);
		std::thread t3(sum, arr1[2] + 1, arr1[3], arr2[2] + 1, arr2[3]);
		std::thread t4(sum, arr1[3] + 1, arr1[4], arr2[3] + 1, arr2[4]);
		t1.join();
		t2.join();
		t3.join();
		t4.join();
		auto end = std::chrono::steady_clock::now();
		time = end - start;
		return;
	}

	void thread8(std::vector<int>& v1, std::vector<int>& v2, std::chrono::duration<double>& time) {
		std::vector<int>::iterator arr1[9];
		std::vector<int>::iterator arr2[9];
		arr1[0] = v1.begin();
		arr2[0] = v2.begin();
		size_t n1 = v1.size() / 8;
		size_t n2 = v2.size() / 8;
		for (int i = 0; i < 8; ++i) {
			(arr1[i] + n1) >= v1.end() ? arr1[i + 1] = v1.end() - 1 : arr1[i + 1] = arr1[i] + n1;
			(arr2[i] + n2) >= v2.end() ? arr2[i + 1] = v2.end() - 1 : arr2[i + 1] = arr2[i] + n2;
		}
		auto start = std::chrono::steady_clock::now();
		std::thread t1(sum, arr1[0], arr1[1], arr2[0], arr2[1]);
		std::thread t2(sum, arr1[1] + 1, arr1[2], arr2[1] + 1, arr2[2]);
		std::thread t3(sum, arr1[2] + 1, arr1[3], arr2[2] + 1, arr2[3]);
		std::thread t4(sum, arr1[3] + 1, arr1[4], arr2[3] + 1, arr2[4]);
		std::thread t5(sum, arr1[4] + 1, arr1[5], arr2[4] + 1, arr2[5]);
		std::thread t6(sum, arr1[5] + 1, arr1[6], arr2[5] + 1, arr2[6]);
		std::thread t7(sum, arr1[6] + 1, arr1[7], arr2[6] + 1, arr2[7]);
		std::thread t8(sum, arr1[7] + 1, arr1[8], arr2[7] + 1, arr2[8]);
		t1.join();
		t2.join();
		t3.join();
		t4.join();
		t5.join();
		t6.join();
		t7.join();
		t8.join();
		auto end = std::chrono::steady_clock::now();
		time = end - start;
		return;
	}

	void thread16(std::vector<int>& v1, std::vector<int>& v2, std::chrono::duration<double>& time) {
		std::vector<int>::iterator arr1[17];
		std::vector<int>::iterator arr2[17];
		arr1[0] = v1.begin();
		arr2[0] = v2.begin();
		size_t n1 = v1.size() / 16;
		size_t n2 = v2.size() / 16;
		for (int i = 0; i < 16; ++i) {
			(arr1[i] + n1) >= v1.end() ? arr1[i + 1] = v1.end() - 1 : arr1[i + 1] = arr1[i] + n1;
			(arr2[i] + n2) >= v2.end() ? arr2[i + 1] = v2.end() - 1 : arr2[i + 1] = arr2[i] + n2;
		}
		auto start = std::chrono::steady_clock::now();
		std::thread t1(sum, arr1[0], arr1[1], arr2[0], arr2[1]);
		std::thread t2(sum, arr1[1] + 1, arr1[2], arr2[1] + 1, arr2[2]);
		std::thread t3(sum, arr1[2] + 1, arr1[3], arr2[2] + 1, arr2[3]);
		std::thread t4(sum, arr1[3] + 1, arr1[4], arr2[3] + 1, arr2[4]);
		std::thread t5(sum, arr1[4] + 1, arr1[5], arr2[4] + 1, arr2[5]);
		std::thread t6(sum, arr1[5] + 1, arr1[6], arr2[5] + 1, arr2[6]);
		std::thread t7(sum, arr1[6] + 1, arr1[7], arr2[6] + 1, arr2[7]);
		std::thread t8(sum, arr1[7] + 1, arr1[8], arr2[7] + 1, arr2[8]);
		std::thread t9(sum, arr1[8] + 1, arr1[9], arr2[8] + 1, arr2[9]);
		std::thread t10(sum, arr1[9] + 1, arr1[10], arr2[9] + 1, arr2[10]);
		std::thread t11(sum, arr1[10] + 1, arr1[11], arr2[10] + 1, arr2[11]);
		std::thread t12(sum, arr1[11] + 1, arr1[12], arr2[11] + 1, arr2[12]);
		std::thread t13(sum, arr1[12] + 1, arr1[13], arr2[12] + 1, arr2[13]);
		std::thread t14(sum, arr1[13] + 1, arr1[14], arr2[13] + 1, arr2[14]);
		std::thread t15(sum, arr1[14] + 1, arr1[15], arr2[14] + 1, arr2[15]);
		std::thread t16(sum, arr1[15] + 1, arr1[16], arr2[15] + 1, arr2[16]);
		t1.join();
		t2.join();
		t3.join();
		t4.join();
		t5.join();
		t6.join();
		t7.join();
		t8.join();
		t9.join();
		t10.join();
		t11.join();
		t12.join();
		t13.join();
		t14.join();
		t15.join();
		t16.join();
		auto end = std::chrono::steady_clock::now();
		time = end - start;
		return;
	}

	void print(std::string s, std::chrono::duration<double> a, std::chrono::duration<double> b, 
		std::chrono::duration<double> c, std::chrono::duration<double> d) {
		std::cout << s << '\t' << a.count() << '\t' << b.count() << '\t' << c.count() << '\t' << d.count() << "\n";
	}
	
	
int main() {
	setlocale(LC_ALL, "rus");
	std::thread t1;
	t1 = std::thread(num_CPU);
	t1.join();
	std::vector<int> v1(1000, 2);
	std::vector<int> v2(10000, 2);
	std::vector<int> v3(100000, 2);
	std::vector<int> v4(1000000, 2);
	std::vector<int> v5(1000, 3);
	std::vector<int> v6(10000, 3);
	std::vector<int> v7(100000, 3);
	std::vector<int> v8(1000000, 3);
	std::cout << "\t\t   1000 \t   10000 \t   100000 \t   1000000 \n";
	std::chrono::duration<double> time1_1;
	std::chrono::duration<double> time1_2;
	std::chrono::duration<double> time1_3;
	std::chrono::duration<double> time1_4;
	std::chrono::duration<double> time2_1;
	std::chrono::duration<double> time2_2;
	std::chrono::duration<double> time2_3;
	std::chrono::duration<double> time2_4;
	std::chrono::duration<double> time4_1;
	std::chrono::duration<double> time4_2;
	std::chrono::duration<double> time4_3;
	std::chrono::duration<double> time4_4;
	std::chrono::duration<double> time8_1;
	std::chrono::duration<double> time8_2;
	std::chrono::duration<double> time8_3;
	std::chrono::duration<double> time8_4;
	std::chrono::duration<double> time16_1;
	std::chrono::duration<double> time16_2;
	std::chrono::duration<double> time16_3;
	std::chrono::duration<double> time16_4;
	thread1(v1, v5, time1_1);
	thread1(v2, v6, time1_2);
	thread1(v3, v7, time1_3);
	thread1(v4, v8, time1_4);
	thread2(v1, v5, time2_1);
	thread2(v2, v6, time2_2);
	thread2(v3, v7, time2_3);
	thread2(v4, v8, time2_4);
	thread4(v1, v5, time4_1);
	thread4(v2, v6, time4_2);
	thread4(v3, v7, time4_3);
	thread4(v4, v8, time4_4);
	thread8(v1, v5, time8_1);
	thread8(v2, v6, time8_2);
	thread8(v3, v7, time8_3);
	thread8(v4, v8, time8_4);
	thread16(v1, v5, time16_1);
	thread16(v2, v6, time16_2);
	thread16(v3, v7, time16_3);
	thread16(v4, v8, time16_4);
	
	print("1 поток\t", time1_1, time1_2, time1_3, time1_4);
	print("2 потока", time2_1, time2_2, time2_3, time2_4);
	print("4 потока", time4_1, time4_2, time4_3, time4_4);
	print("8 потоков", time8_1, time8_2, time8_3, time8_4);
	print("16 потоков", time16_1, time16_2, time16_3, time16_4);

	return 0;
}