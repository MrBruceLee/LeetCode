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
        
        // put remained characters into buffer first.
        while(remains.empty() == false) {
            if(m < n) {
                buf[m++] = remains.front();
                remains.pop();
                
                // return here, when n <= remains.size()
            } else {
                return m;
            }
        }
        
        // continue to read if n > remains.size()
        while(m < n) {
            int len = read4(buf + m);
            if(len == 0) {
                break;
            }
            m += len;
        }
        
        // put extra characters into queue, for next read call use
        if(m > n) {
            for(int i = n; i < m; i++) {
                remains.push(buf[i]);
            }
        }
        
        return (int)min(m, n);
    }
    
private:
    queue<char> remains;
};