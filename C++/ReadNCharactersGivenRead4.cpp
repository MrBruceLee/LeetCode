// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        // m is the lenght of characters that actually read from the file
        int m = 0;
        
        while(m < n) {
            int len = read4(buf + m);
            if(len == 0) {
                break;
            }
            m += len;
        }
        
        return (int)min(m, n);
    }
};