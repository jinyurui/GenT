Doxygen
****************

Create doxyfile
+++++++++++++++++++
.. code::

    Doxygen.exe -g

Edit doxyfile
+++++++++++++++++++

+----------------------+-------------------------------+
|        key           |           desc                |
+======================+===============================+
| PROJECT_NAME         |     GenT V1.0                 |
+----------------------+-------------------------------+
| PROJECT_LOGO         |     log.png                   |
+----------------------+-------------------------------+
| OUTPUT_DIRECTORY     |     build out put dir         |
+----------------------+-------------------------------+
| INPUT                |     the documented source file|
+----------------------+-------------------------------+
| LAYOUT_FILE          |     layout file               |
+----------------------+-------------------------------+
| ALIASES              |     alias                     |
+----------------------+-------------------------------+
| EXAMPLE_PATH         |     example for \INCLUDE      |
+----------------------+-------------------------------+
| GENERATE_HTML        |     the flag to GENERATE_HTML |
+----------------------+-------------------------------+
| HEML_HEADER          |     html header file          |
+----------------------+-------------------------------+
| HTML_FOOTER          |     html footer file          |
+----------------------+-------------------------------+
| HTML_EXTRA_STYLESHEET|     css file                  |
+----------------------+-------------------------------+
| DISABLE_INDEX        |     the flag disable index    |
+----------------------+-------------------------------+
| GENERATE_TREEVIEW    |     the flag generate treeview|
+----------------------+-------------------------------+
| TREEVIEW_WIDTH       |     the width of tree         |
+----------------------+-------------------------------+
| GENERATE_MAN         |     the flag generate man page|
+----------------------+-------------------------------+
| GENERATE_XML         |     the flag to GENERATE_XML  |
+----------------------+-------------------------------+
| PREDEFINED           |     predefined macro          |
+----------------------+-------------------------------+
| EXCLUDE_SYMBOL       |     exclude from the output   |
+----------------------+-------------------------------+

Run
++++++++++++
.. code::

    Doxygen.exe doxyfile

Example
++++++++++++


fileDir

    - source
    - examples
    - docs
    
        - Config
        
            - logo.png
            - DoxygenLayout.xml
            - new_stylesheet.css
            - Some.md
            - define.h
            - new_header.html
            - new_footer.html
     
        - doxygen

            - doxygen[file]

        - docs[output]

doxyfile

.. code::

    PROJECT_NAME           = "GenT V1.0"
    PROJECT_LOGO           = ../Config/logo.png
    OUTPUT_DIRECTORY       = ../docs
    INPUT                 += ../Config/Some.md
    INPUT                 += ../Config/define.h
    INPUT                 += ../../source
    ALIASES                = "codeStart = <pre class=\"fragment\">" \
                            "codeEnd = </pre>" \
    LAYOUT_FILE            = ../Config/DoxygenLayout.xml
    EXCLUDE_SYMBOLS        = some_exclude_*
    EXAMPLE_PATH           = ..\..\examples\

    GENERATE_HTML          = YES
    HTML_OUTPUT            = html
    HTML_FILE_EXTENSION    = .html
    HTML_HEADER            = ../Config/new_header.html
    HTML_FOOTER            = ../Config/new_footer.html
    HTML_EXTRA_STYLESHEET  = "../Config/new_stylesheet.css"
    DISABLE_INDEX          = YES
    GENERATE_TREEVIEW      = YES
    TREEVIEW_WIDTH         = 300
    GENERATE_MAN           = NO
    GENERATE_XML           = YES
    PREDEFINED             = "__cplusplus"
    PREDEFINED            += "_WIN32"
