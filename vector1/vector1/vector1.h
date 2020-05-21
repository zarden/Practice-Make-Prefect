#pragma once
#include<assert.h>

namespace ywt
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		//v2(v1)
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(v.capacity());
			for (const auto& e : v)
				push_back(e);
		}

		//v1=v3
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		void swap(vector<T>& v)
		{
			::swap(_start, v._start);
			::swap(_finish, v._finish);
			::swap(_endofstorage, v._endofstorage);
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				iterator tmp = new iterator[n];
				if (_start)
				{
					//memcpy(tmp,_start,sizeof(T)*sz);按字节拷贝->浅拷贝
					for (size_t i = 0; i < sz; ++i)
					{
						//调用的是T的operator= 深拷贝
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = tmp + sz;
				_endofstorage = tmp + n;

 			}
		}

		void resize(size_t n, const T& value = T())
		{
			if (n<size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n>capacity())
				{
					reserve(n);
				}
				while (_finish<_start+n)
				{
					*_finish = value;
					++_finish;
				}
			}
		}

		void push_back(const T& x)
		{
			insert(_finish, x);
		}

		void pop_back()
		{
			erase(_finish - 1);
		}

		void insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			if (_finish == _endofstorage)
			{
				size_t n = pos - _start;
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
				//增容后原来pos失效(pos指向旧空间)，需要重新计算其位置
				pos = _start + n;
			}

				iterator end = _finish - 1;
				while (pos<=end)
				{
					*(end + 1) = *end;
					++end;
				}

				*pos = x;
				++_finish;
		}

		iterator erase(iterator pos)
		{
			assert(pos < _finish);
			iterator it = pos;
			while (it<_finish)
			{
				*it = *(it + 1);
				++it;
			}
			--_finish;
			return pos;
		}

		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}

		const T& operator[](size_t i)const
		{
			assert(i < size());
			return _start[i];
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endofstorage - _start;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
}