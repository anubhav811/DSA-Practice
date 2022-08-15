
void findmin_ex(char* s, int now, int len, int* ans){
    while (now < len){
        while (s[len] == 'A'){
            len--;
        }
        if(s[now] == s[len]){
            return;
        } else {
            int copy = now+1;
            if (s[copy] == 'A'){
                *ans -= 1;
            }
            while(s[len] != s[copy]){
                copy++;
                if (s[copy] == 'A'){
                    *ans -= 1;
                }
            }
            *ans += copy-now;
            s[copy] = 'A';
            len--;
        }
    }
}

void findmin(char* s, int now, int len, int* ans){
    while (now < len){
        while (s[now] == 'A'){
            now++;
        }
        while (s[len] == 'A'){
            len--;
        }
        if(s[now] == s[len]){
            now++;
            len--;
        } else {
            int copy = len-1;
            int copya = *ans;
            if (s[copy] == 'A'){
                *ans -= 1;
            }
            while(s[now] != s[copy]){
                copy--;
                if (s[copy] == 'A'){
                    *ans -= 1;
                }
            }
            if (copy != now){
                *ans += len-copy;
                s[copy] = 'A';
            } else {
                *ans = copya;
                findmin_ex(s, now, len, ans);
                return;
            }
            now++;
        }
    }
}

int minMovesToMakePalindrome(char * s){
    int len = strlen(s);
    int ans = 0;
    findmin(s, 0, len-1, &ans);
    return ans;
}
