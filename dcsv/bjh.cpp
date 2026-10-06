#include <iostream>
using namespace std;
class vector{
	private:
		int x , y;
	public:
		vector(int x=0, int y=0 ):x(x),y(y){}
		int& operator[](int index){
			if (index==0) return x;
			else return y;
		}
		void hienthi()
    {
        cout << "(" << x << "," << y << ")";
    }
    int operator()(vector &v){
    	return x*v.x+y*v.y;
	}
		
};
int main(){
	vector v1(1,2), v2(2,3);
	int tichvohuong=v1(v2);
	cout<<tichvohuong;
	vector v(1,2);
	v[0]=3;
	v.hienthi();
	return 0;
}