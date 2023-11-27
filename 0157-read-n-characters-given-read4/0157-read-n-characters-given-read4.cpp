/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int c = 0, r = 4;
        char buf4[4];

        while(c < n && r == 4){
            r = read4(buf4);
            for(int i = 0;i<r;i++){
                if(c == n){
                    return c;
                }
                buf[c] = buf4[i];
                c++;
            }
        }
        return c;
    }
};