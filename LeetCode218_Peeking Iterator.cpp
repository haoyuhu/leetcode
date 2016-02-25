// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    this->nums = nums;
	    this->length = nums.size();
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
		if (isInRange(this->index, this->length)) {
			return nums[this->index];
		}
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		if (isInRange(this->index, this->length)) {
			return nums[this->index++];
		}
	}

	bool hasNext() const {
	    return isInRange(this->index, this->length);
	}
private:
	vector<int> nums;
	int index = 0, length;

	bool isInRange(const int index, const int length) const {
		return index + 1 <= length && index >= 0;
	}
};