#ifndef __BOUND_CHECK_ARRAY_H__
#define __BOUND_CHECK_ARRAY_H__

template <typename T>
class BoundCheckArray
{
private:
	T* arr;
	int arrlen;
	BoundCheckArray(const BoundCheckArray& arr) { }
	BoundCheckArray& operator=(const BoundCheckArray& arr) { }
public:
	BoundCheckArray(int len);
	T& operator[] (int idx);
	T& operator[] (int idx) const;
	int GetArrLen() const;
	~BoundCheckArray();
};

#endif
