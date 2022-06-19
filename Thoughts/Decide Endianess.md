## 如何判断当前机器使用的是大端序还是小端序？
1. int i = 1;
2. integer i occupy 4 chars. if it's small endian, then the first char of it should be 1, otherwise it's 0.
3. char* ptr = (char*)&i;
4. check the value of *ptr.