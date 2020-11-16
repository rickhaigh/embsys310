// Test with func1 needing 5 arguments called by func2

void func1(int a, int b, int c, int d, int e);
void func2();

void func1(int a, int b, int c, int d, int e){

}

void func2(){
    func1(21,22,23,24,25);
}

int main() {
    func2();
    
    func1(10, 11, 12, 13, 14);
    return 256;
}
