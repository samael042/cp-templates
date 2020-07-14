class SegmentTree {
public:
	vector<int> seg;
	int n;

	SegmentTree(vector<int> a1) {
		n = a1.size();
		seg.resize(4*n+4);
		for(int i = 0; i < n; i++) {
			insert(i, a1[i]);
		}
	}

	void insert(int cur, int start, int end, int index, int val) {
		if(index > end || index < start) {
			return;
		}
		if(start == end) {
			seg[cur] = val;
			return;
		}
		insert(2*cur+1, start, (start+end)/2, index, val);
		insert(2*cur+2, (start+ end)/2 + 1, end, index, val);
		seg[cur] = seg[2*cur + 1] + seg[2*cur+2];
	}

	void insert(int index, int val) {
		insert(0, 0, n-1, index, val);
	}

	int sum(int node, int start, int end, int ql, int qr) {
		if(ql > end || qr < start) return 0;
		if(start >= ql and end <= qr) return seg[node];
		return sum(2*node + 1, start, (start + end) / 2, ql, qr) + sum(2*node + 2, (start + end)/2 + 1, end, ql, qr);
	}

	int sum(int l, int r) {
		return sum(0, 0, n-1, l, r);
	}

};
