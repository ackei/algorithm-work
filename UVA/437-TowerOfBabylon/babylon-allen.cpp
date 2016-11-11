#include <cstdio>
#include <vector>

struct Block{
	Block(int l, int w, int h) : l(l), w(w), h(h), d(h), checked(0) {}
	int l;
	int w;
	int h;
	int d;
	bool checked;
};

typedef std::vector<Block> vb;
typedef std::vector<int> vi;
typedef std::vector< vi > vvi;

int main(){
	int n, c = 1;
	while (scanf("%d",&n),n){
		int size = 6 * n;
		vb block_list;
		int l, w, h;
		while (n--){
			scanf("%d %d %d",&l,&w,&h);
			block_list.push_back(Block(l,w,h));
			block_list.push_back(Block(l,h,w));
			block_list.push_back(Block(w,l,h));
			block_list.push_back(Block(w,h,l));
			block_list.push_back(Block(h,w,l));
			block_list.push_back(Block(h,l,w));
		}

		vvi adj_list(size);
		for (int i = 0; i < size; i++){
			Block& block_i = block_list[i];
			for (int j = 0; j < size; j++){
				Block& block_j = block_list[j];
				if (block_i.l < block_j.l && block_i.w < block_j.w)
					adj_list[i].push_back(j);
			}
		}
		int source_blocks[size];
		for (int i = 0; i < size; i++)
			source_blocks[i] = 1;
		for (int i = 0; i < size; i++){
			for (int j = 0; j < adj_list[i].size(); j++){
				source_blocks[j] = 0;
			}
		}
		for (int i = 0; i < size; i++)
			if (source_blocks[i])
				block_list[i].checked = true;
		int max_height = 0;
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++){
				int numchecked = 0;
				for (int k = 0; k < size; k++){
					if (block_list[k].checked)
						numchecked++;
				}
				if (numchecked == size)
					break;
			}
		}
	}
}
