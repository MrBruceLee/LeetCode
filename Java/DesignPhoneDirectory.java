public class PhoneDirectory {
    
    /** Initialize your data structure here
     @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    public PhoneDirectory(int maxNumbers) {
        numbers = new Boolean[maxNumbers];
        pool = new LinkedList<Integer>();
        for(int i = 0; i < maxNumbers; i++) {
            numbers[i] = true;
            pool.offer(i);
        }
    }
    
    /** Provide a number which is not assigned to anyone.
     @return - Return an available number. Return -1 if none is available. */
    public int get() {
        if(pool.isEmpty() == true) {
            return -1;
        }
        int number = pool.poll();
        numbers[number] = false;
        return number;
    }
    
    /** Check if a number is available or not. */
    public boolean check(int number) {
        return numbers[number];
    }
    
    /** Recycle or release a number. */
    public void release(int number) {
        if(numbers[number] == true) {
            return;
        }
        pool.offer(number);
        numbers[number] = true;
    }
    
    Boolean[] numbers;
    Queue<Integer> pool;
}

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * boolean param_2 = obj.check(number);
 * obj.release(number);
 */