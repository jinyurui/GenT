Git
===================
Normal
-------------------
.. code::

    // create branch
    git checkout -b branchName
    
    // state check
    git status

    // git add
    git add $file
    git add .

    // commit msg
    git commit -m "you do something"

    // push origin branch
    git push origin branchName

Easy work flow
--------------------
.. code::

    // to do new task
    git checkout develop
    git pull 
    git checkout -b newTask
    ...

Work help
----------------------
.. code::

    // fetch
    git checkout develop
    git pull
    git fetch -a
    git checkout helpTask
    ...

Back
-----------------------
.. code::

    // how to back 
    // no add, file will cover
    git checkout -- yourfile

    // add, no commit(need test)
    git reset --mixed id  or git reset yourfile

    // commit
    git reset --soft id

    // commit and push
    git revert

Advance
---------------------
.. code::

    // advance, sparse-checkout
    git sparse-checkout list
    git push --set-upstream origin branchName

    // delete local branch
    git branch D
    git branch d

    // log 
    git log

    //still can  see r-branch that has been deleted
    git remote show origin
    git remote prune origin

    
    // git pick, pick A.commit1 to B branch
    on branch A
    copy the commit id
    on branch B
    git cherry-pick id
    fix 
    git add
    edit commit msg
    git cherry-pick --continue

    // show where create the branch
    on branchName
    git reflog show branchName
