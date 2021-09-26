WriteBooks
******************
Create a sphinx project, use Github for version control, and host it in readthedocs.

Create Github repository
+++++++++++++++++++++++++++++
Create a github account and create a new one repository, Clone to local.

Create sphinx project
+++++++++++++++++++++++++++++
In the project root directory, use shell window

.. code::

     sphinx-quickstart.exe
     config project name, user, version

after that, this should be like

.. code::

    .git
    build          // auto create
        doctrees   // auto ouput
        html       // auto ouput  index.html
    source
        conf.py    // user edit
        index.rst  // user edit
    make
    Makefile

Edit
++++++++++++++++++++
edit config.py

.. code::

    html_theme = 'sphinx_book_theme'

edit your index.rst

Sync Github
++++++++++++++++
update the local and push origen main

ReadTheDocs host
++++++++++++++++
Register an account, import the path of the github repository, and the branch name, and start building.
If successful, this will be linked in /setting/webhooks on github.
Every time the github document is updated, it will be automatically rebuilt.

Aecess you page
++++++++++++++++
projectName.readthedocs.io

Advance
++++++++++++++++
You can add a .readthedocs.yaml and requirements.txt in the root path.

.. _Cfgreadthedocs: https://docs.readthedocs.io/en/stable/config-file/v2.html

See Cfgreadthedocs_ for details.

