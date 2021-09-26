Sphinx
##########
python docs generater, you can use it create docs for c++ project or write books

Todo
************
- fix the pip install custom package
- create docs form cpp project
- delegate your web by Github
- delegate books by readthedocs
- rst fromat

keywords
************
- docs
- doxygen https://www.doxygen.nl/index.html
- breathe https://www.breathe.readthedocs.io
- sphinx  
- reStructureText
- exhale
- ReadTheDocs https://readthedocs.org
- Sphinx_theme https://sphinx-themes.org
- Github

SetUp win10
******************
download python 3.9.6
+++++++++++++++++++++++
path: https://www.python.org/downloads/release/python-396/

.. note::

    make sure python and pip are ok.

install breathe
+++++++++++++++++++++++++++
.. code::

    pip install breathe

install sphinx_rtd_theme
+++++++++++++++++++++++++++
.. code::

    pip install sphinx_rtd_theme

install copy button
+++++++++++++++++++++++++++
.. code::

    pip sphinx_copybutton

Create cpp project docx
**************************
[comments] >> [doxygen: xml] >> [breathe][sphinx: html]

- comments for code with the doxygen origen words
- config the doxygen file

    + create the config file

        .. code::

            doxygen -g file
    + edit the file

        .. code::
            
            INPUT += "include"
            INPUT += "codeSrc"
            OUTPUT_DIRECTORY = "build"
            GENERATE_XML = YES
     
- run doxygen, out put xml files
- sphinx

    + sphinx quick, create dox tree 
    + edit config.py

        .. code::

            extensions = ['breathe','sphinx_copybutton']
            html_theme = 'sphinx_rtd_theme' 

    + edit index.rst
    + edit custom rst(reStructureText)
    + make.bat html

