Create cpp project docx
********************************
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

    .. note::
        
        about theme, more can see `themes <https://sphinx-themes.org>`_.

    + edit index.rst
    + edit custom rst(reStructureText)
    + make.bat html