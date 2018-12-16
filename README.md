# LeetCode Practice 

**sparse checkout** : check individual folder or directory instead of all of folders.

In order to sparse checkout you need to use:
```bash
mkdir <repo>
cd <repo>
git init
git remote add -f origin https://github.com/ryanfakir/leetcode.git

# config sparse checkout as true
git config core.sparseCheckout true

# go ahead to checkout which folder directory you want to checkout
echo "some/dir/" >> .git/info/sparse-checkout
echo "another/sub/tree" >> .git/info/sparse-checkout

# check out
git pull origin master
```