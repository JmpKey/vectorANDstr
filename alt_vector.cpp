#include <iostream>

template <typename T> class r_vector
{
private:
	T* arr_p_rewrite;
	int arr_size;
public:
	void push_back(T _data)
	{
		T* arr_p_realloc = new T[++this->arr_size];

		for (size_t i = 0; i < this->arr_size; i++)
		{
			if (i != this->arr_size - 1)
			{
				arr_p_realloc[i] = this->arr_p_rewrite[i];
			}
			else
			{
				arr_p_realloc[i] = _data;
				break;
			}
		}
		delete[] this->arr_p_rewrite; // отчиска прошлого куска
		this->arr_p_rewrite = arr_p_realloc; // переход на новый
	}

	T pop()
	{
		return this->pop_index(this->arr_size - 1);
	}

	void clear()
	{
		if (this->arr_p_rewrite != NULL)
		{
			::ZeroMemory(this->arr_p_rewrite, this->arr_size); // заполнение памяти p нулями
		}
		this->arr_size = 0;
		this->arr_p_rewrite = new T[this->arr_size];
	}

	T operator [](int _index)
	{
		return this->arr_p_rewrite[_index];
	}

	int size()
	{
		return this->arr_size;
	}

	void push_index(T _data, int _index)
	{
		int oldSize = this->arr_size;

		this->arr_size = (this->arr_size >= _index) ? (++this->arr_size) : (this->arr_size + (_index - this->arr_size));

		T* arr_p_realloc = new T[this->arr_size];

		int arr_index = 0;

		for (size_t ind2 = 0; ind2 < this->arr_size; ind2++)
		{
			if (ind2 == ind2)
			{
				arr_p_realloc[ind2] = _data;
				continue;
			}

			if (arr_index != oldSize)
			{
				arr_p_realloc[ind2] = this->arr_p_rewrite[arr_index++];
			}
		}
		delete[] this->arr_p_rewrite;
		this->arr_p_rewrite = arr_p_realloc;
	}

	T pop_index(int _index)
	{
		T* arr_p_realloc = new T[--this->arr_size];

		T resItem;

		int resIndex = 0;

		for (int index2 = 0; index2 < this->arr_size + 1; index2++)
		{
			T item = this->arr_p_rewrite[index2];

			if (_index == index2)
			{
				resItem = item;
				continue;
			}
			arr_p_realloc[resIndex++] = this->arr_p_rewrite[index2];
		}
		delete[] this->arr_p_rewrite;
		this->arr_p_rewrite = arr_p_realloc;
		return resItem;
	}

	r_vector()
	{
		this->arr_size = 0;
		this->arr_p_rewrite = new T[this->arr_size];
	}
};

int main()
{
	r_vector<int> v_obj;
	int size;

	std::cout << "Size: " << std::endl;
	std::cin >> size;
	//for (int index = 0; index < size; _vector.push_back(index++));
	v_obj.push_back(10); v_obj.push_back(2); v_obj.push_back(3); v_obj.push_back(100); v_obj.push_back(75); v_obj.push_back(1);

	int max = 0; int min = 0; int sr_arifmet = 0;

	for (size_t i = 0; i < v_obj.size(); i++) {
		if (v_obj[i] > max) max = v_obj[i];
	}

	min = max;

	for (size_t i = 0; i < v_obj.size(); i++) {
		if (v_obj[i] < min) min = v_obj[i];
	}

	for (size_t i = 0; i < v_obj.size(); i++) {
		sr_arifmet += v_obj[i];
	}

	printf("min %d\tmax %d\t sr_arifmet %d\n", min, max, sr_arifmet / v_obj.size());

    system("pause");
    return 0;
}