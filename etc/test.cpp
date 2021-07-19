/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>

using namespace std;


int arr[2000][2000];
int main(int argc, char** argv)
{
    int T, test_case;
   

    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        memset(arr, 0, sizeof(arr));
        int n, k, one,two,three,four;
        cin>>n>>k;
        for (int i=0; i<k; i++){
            cin>>one;
            if (one==1){
                cin>>two>>three>>four;
                if (arr[two][three] == four || arr[two][three] == 0){
                    arr[two][three] = four;
                    arr[three][two] = -four;
                }
                else{
                    arr[two][three] = 123456;
                    arr[three][two] = 123456;
                }
            }
        }
       
        // Print the answer to standard output(screen).
        cout << "Case #" << test_case+1 << endl;
        
    }

    return 0;//Your program should return 0 on normal termination.
}
