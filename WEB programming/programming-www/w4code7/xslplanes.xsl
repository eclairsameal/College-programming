<?xml version = "1.0"?>
<!-- xslplanes.xsl -->

<xsl:stylesheet version = "1.0"
                xmlns:xsl = "http://www.w3.org/1999/XSL/Transform"
                xmlns = "http://www.w3.org/1999/xhtml" >

<!-- The template for the whole document (the planes element) -->

   <xsl:template match = "planes">
      <h2> Airplane Descriptions </h2>

<!-- Apply the following to all occurrences of the plane element -->

      <xsl:for-each select = "plane">
         <span style = "font-style: italic"> Year: </span>
         <xsl:value-of select = "year" /> <br />
         <span style = "font-style: italic"> Make: </span>
         <xsl:value-of select = "make" /> <br />
         <span style = "font-style: italic"> Model: </span>
         <xsl:value-of select = "model" /> <br />
         <span style = "font-style: italic"> Color: </span>
         <xsl:value-of select = "color" /> <br /> <br />
      </xsl:for-each>

   </xsl:template>
</xsl:stylesheet>
