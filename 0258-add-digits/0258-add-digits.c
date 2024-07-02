int addDigits(int num) {
        if(num<10) return num;
        int a = 0;
        while(num>0){
            a+=num%10;
            num=num/10;
        }
        return addDigits(a);
    }