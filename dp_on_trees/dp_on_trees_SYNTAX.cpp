int solve(Node *root, int& res) {
	// BC: Almost same in all questions
	if(root == nullptr)
		return;

	// Hypothesis: Same in all questions
	int left = solve(root->left, res);
	int right = solve(root->right, res);

	// Only change in induction step for different questions
	int temp =  _____;
	int ans = max(temp, _____);
	res = max(res, ans);

	return temp;
}