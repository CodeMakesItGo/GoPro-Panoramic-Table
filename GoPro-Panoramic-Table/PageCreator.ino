const char STYLE_CSS[] =
 "<style>"
"div.container {"
    "width: 100%;"
    "border: 1px solid gray;"
"}"
""
"header, footer {"
    "padding: 1em;"
    "color: white;"
    "background-color: black;"
    "clear: left;"
    "text-align: center;"
"}"
""
".floating-littlebox {"
    "display: inline-block;"
    "width: 200px;"
    "height: 20px;"
    "margin: 10px;"
     "text-align: center;"
"}"
".floating-box {"
    "display: inline-block;"
    "width: 200px;"
    "height: 200px;"
    "margin: 10px;"
"}"
    ""
    ".after-box {"
    "border: 1px solid #fff; "
"}"
""
""
"</style>";
  
void buildPageHeader() 
{
  webSite = "<!DOCTYPE HTML>\n";
  webSite += "<html>";
  webSite += "<head>";
  webSite += STYLE_CSS;
  webSite += "</head>";
   
  webSite += "<BODY'>\n";

  webSite += "<header>";
  webSite += "<h1>Code Makes It Go!</h1>\n";
  webSite += "</header>";
}

void buildPageFooter(const char* javascript) 
{
  //http://base64.wutils.com/encoding-online/
 
  webSite += "<footer>";
  webSite += "<a href=\"/\">";
  webSite += "<img alt=\"icon_sm.png\" src=\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAEEAAAAwCAYAAABOiRchAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsIAAA7CARUoSoAAAATzSURBVGhD7ZlbaFxFGMf/m81tN9mEZJtGA2kiESSYIsmDJsWkKF5ACG1JEWkf2iooqBSKoPhQteCDINgX+1KxFSElIJQiCCKUtqGgFow1JGpvuTT2QrINabpJNptN6vefzIFtSbdnZrObhJ4fDHvmm92zM/+5fd+M766AR5wc/flI44kgeCIIngiCJ4LgiSCkvUUm5udx8do15Ph82vJw5hcWUFlWhnUlJSp/+fp1zCUS8Ll8Byuc5/fjyaqqRUOapCVC15kzOHn+PAL5+fIm9yLEZmexvbUVrzQ1qfxnnZ0Ym5iAXxrmlrsi5IJU/d32djy9YYO22mE9HSjA2f5+1Zu5Unm+yG1SPZ4kGvNMS333QalAhA8Fgzh4/DhGxsbEYo/VSIjL0H3/0CGERYCpWAxbN21CaVERFqR33MDpULN+PR4vL1f5vwYHMRuPL4rjAor+x6VL+GdkBP6cHIQCAezfsUOXmmMlwrkLF9B56pSqTFtDA7a0tOiS7PLx0aNg9cejURzeu1dbzeHIMiYqvc+FkD1aFQ5ra/Z5TEYS1wUuklOyzthiJULyoHU7BTKBM4jdL8lLYyWCDb04gJN4SedWF1kTIYJfMSwyfCv91o8vtXV1kDUR/ChAnnwGJJ3Dh+gUMUZxVpWtNFkTwYHzt3DxET+iFT/hGcxhWlvMsPby7sNKBO7N6cI3FEkal9XiO3n6He8ouy0mbvv9WLVmaHRUubhcnfPzOMjtyZVEMf7FYRHDhwF8r+xuKJT/Zh1Ylxu3bmmrOcYifHTkCP68ckXtzbNzc9hYW6tL7GEfSvSh0mnswg8owyQusiglDTU1KvAKFhTg4IkT6Oru1iVmGIsQmZxUAdOcRI/0Fuk1LhcUgwvnDCbwDZ5StlS0yv/n6KmZn5uL8Tt31LMpxiJUlJZiRvx8joTuvj4lxnLBhW5GUhBhvI3LypYK/r/jrHFErAuF1LMpxiJ8sWcPGuvqVOMLZE72DQ3pEnvY+LhOL8jmuV28ihDqWJSS/uFh5MkIoMu8b9s2vN7WpkvMMBaB1EoEOC8iMOrjupAOCUlTkurxHnaLHE/AfTQYk/9mHRakLowjbLESgYGTg+3GxDew8WE04k3E8Cy+VnZbGEjZYiVCOrCqMUk+8SG34De8hh7lTdpg7xncS9ZEmJemc+Jw4WvGVzLoE6jAc6pspcmaCBV4HrV4FW/JWKjHPm1dHWRNhI3Yjxfxs86tLqxESD6Rc5yVlcA5k2RtkutkilULigMBtRozkPovEtHW7HNjfFwFTvRZigud2NScZTltbm9uRnlxsettihc2NZWVqHJOmwcGlL9hctrMw15e+rAj2CmfZPu0mTj3DjzuZgNMzhrpdnfw8qWxUeUPHDumLl9y3U4tEYtuO6PHyO3b+HTnTlRXVOhCc6wn9BubN6sAigFVQgRQ89JlUiRrr5+Tv5MyyfdjImR0ehofdHSkJQBJ6xqOcAT8ffUq4nSjtc2hUKLNpQ476HGy4hxFZPDmTczyLlLl7oXzncFRMqxySTC4Ou4iH8YvPT2IzswsuYNwXXDcbwZBS4nFtadJgrXlauyDyKgIn3d1IWJ40ZoMh/zWlha8rC9uM0VGN3nqyx2DnzZJ/Va/K5NkdCSc7u3FtMT6toegXA/qq6vX9nRYK2R0OqwVPBEETwTBE0HwRBA8EQRPBAD/AytWEC2cn1sLAAAAAElFTkSuQmCC\" />\n";
  webSite += "</a>";
  
  webSite += (String)ip[0];
  webSite += ".";
  webSite += (String)ip[1];
  webSite += ".";
  webSite += (String)ip[2];
  webSite += ".";
  webSite += (String)ip[3];
  webSite += "</footer>";

  webSite += javascript;
  
  webSite += "</BODY>\n";
  
  webSite += "</HTML>\n";
}

String InsertChecked(bool b)
{
   if(b)
   {
    return "checked";
   }

   return "";
}

void HomePage()
{
 webSite += "<p id='HomeDisplay'></p>";

 webSite += " <br><br>";
 webSite += "<P>Settings:</P>";
 webSite += "<form action=\"/\">";
 webSite += " One rotation every:<br>";
 
 webSite += "   <input type=\"radio\" name=\"rpm\" value=\"5\"";
 webSite += InsertChecked(stepperDelay == 5);
 webSite += "> 10 Seconds<br>";
 
 webSite += "   <input type=\"radio\" name=\"rpm\" value=\"15\"";
 webSite += InsertChecked(stepperDelay == 15);
 webSite += " > 30 Seconds<br>";
 
 webSite += "   <input type=\"radio\" name=\"rpm\" value=\"30\"";
 webSite += InsertChecked(stepperDelay == 30);
 webSite += "> 1 Minute<br>";
 
 webSite += "   <input type=\"radio\" name=\"rpm\" value=\"150\"";
 webSite += InsertChecked(stepperDelay == 150);
 webSite += "> 5 Minutes<br>";
 
 webSite += "   <input type=\"radio\" name=\"rpm\" value=\"900\"";
 webSite += InsertChecked(stepperDelay == 900);
 webSite += "> 30 Minutes<br>";
 
 webSite += "   <input type=\"radio\" name=\"rpm\" value=\"1800\"";
 webSite += InsertChecked(stepperDelay == 1800);
 webSite += "> 1 Hour<br>";
 
 webSite += "   <input type=\"radio\" name=\"rpm\" value=\"3600\"";
 webSite += InsertChecked(stepperDelay == 3600);
 webSite += "> 2 Hours<br>";
 
 webSite += "   <input type=\"radio\" name=\"rpm\" value=\"7200\"";
 webSite += InsertChecked(stepperDelay == 7200);
 webSite += "> 4 Hours<br>";
 
 webSite += "   <input type=\"radio\" name=\"rpm\" value=\"14400\"";
 webSite += InsertChecked(stepperDelay == 14400);
 webSite += "> 8 Hours<br>";
 
 webSite += "   <input type=\"radio\" name=\"rpm\" value=\"21600\"";
 webSite += InsertChecked(stepperDelay == 21600);
 webSite += "> 12 Hours<br>";
 
 webSite += "   <input type=\"radio\" name=\"rpm\" value=\"43200\"";
 webSite += InsertChecked(stepperDelay == 43200);
 webSite += "> 24 Hours<br>";
 
 webSite += " <br><br>";
 
 webSite += " High Power Mode:<br>";
 webSite += "   <input type=\"radio\" name=\"hpm\" value=\"0\"";
 webSite += InsertChecked(highPowerMode == false);
 webSite += "> High Power Mode OFF (Low rotation resistance and battery usage)<br>";
 
 webSite += "   <input type=\"radio\" name=\"hpm\" value=\"1\"";
 webSite += InsertChecked(highPowerMode == true);
 webSite += " > High Power Mode ON (Higher rotation resistance and battery usage)<br>";
 webSite += "<p>High Power Mode is best used when there are high winds or the USB battery pack keeps turning off due to low current.</p>";
 webSite += "<p>Wifi turns off in 5 minutes in either mode.</p>";

 webSite += " <br><br>";
 
 webSite += " Clockwise Mode:<br>";
 webSite += "   <input type=\"radio\" name=\"ccm\" value=\"0\"";
 webSite += InsertChecked(clockwiseMode == false);
 webSite += "> Counter-Clockwise <br>";
 
 webSite += "   <input type=\"radio\" name=\"ccm\" value=\"1\"";
 webSite += InsertChecked(clockwiseMode == true);
 webSite += "> Clockwise <br>";
 webSite += " <input type=\"submit\">";
 webSite += "</form>";
}

void buildHomePage()
{
  buildPageHeader();
  HomePage();
  buildPageFooter("");
}



