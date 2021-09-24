Sphinx
##########
python docs generater, you can use it create docs for c++ project or write books

keywords
************
- doxs
- doxygen
- breath
- sphinx
- exhale
- ReadTheDocs

SetUp win10
******************
download python 3.9.6
+++++++++++++++++++++++
path: https://www.python.org/downloads/release/python-396/

note
make sure python and pip are ok.

install breath
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
[comments] >> [doxygen: xml] >> [breath][sphinx: html]

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

