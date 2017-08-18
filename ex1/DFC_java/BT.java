/*
 * Class of Binary-Tree with a DFS scanning
 * Every tree contain data (int) two mini BT.
 * The tree build in recursion.
 * the tree can make a DFS scan
 */
public class BT {
	int data;
	BT left = null;
	BT right = null;
	// Count the number of the nodes in the whole tree.
	static int number = 1;

	// Constructor
	public BT(int data) {
		this.data = data;
	}

	// Create the root.
	public void createBT(int leaves){
		int height = (int) (Math.log(leaves) / Math.log(2));
		createFullTree(height);
	}

	// Create the whole the in recursive.
	private void createFullTree(int height) {
		this.data = number;
		number++;
		// The return condition.
		if (height == 0){
			return;
		}
		// Create left and than right.
		this.left = new BT(0);
		this.left.createFullTree(height - 1);
		this.right = new BT(0);
		this.right.createFullTree(height - 1);
	}
// Scan the tree with DFS algorithm.
	public void DFSscan(){
		if(this.left != null){
			this.left.DFSscan();
		}
		if (this.right != null){
			this.right.DFSscan();
		}
	}
}
