#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include<DHT.h>           
 

MDNSResponder mdns;
const char* ssid = "No Name";
const char* password = "*taophairua";
const char index_html[] PROGMEM={
"<!DOCTYPE html>\n"
"<html>\n"
"<head>\n"
"\t<title>Thực hành chuyên sâu</title>\n"
"\t  <meta charset=\"utf-8\">\n"
"  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
"  <link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css\">\n"
"  <script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js\"></script>\n"
"  <script src=\"https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js\"></script>\n"
"  <script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js\"></script>\n"
"  <script type=\"text/javascript\" src=\"http://rilwis.googlecode.com/svn/trunk/weather.min.js\"></script>  \n"
"  <style type=\"text/css\">\n"
"  \tspan{\n"
"  \t\tfont-size: 30px;\n"
"  \t}\n"
"  \t.nav-item:hover{\n"
"  \t\tbackground-color: #C6E2FF;\n"
"  \t}\n"
"  \ta{\n"
"  \t\tcolor: #cfcfcf;\n"
"  \t}\n"
"    .content{\n"
"      width: 1000px;\n"
"      height: 50px;\n"
"      background-color: #D3D3D3;\n"
"      padding-left: 50px;\n"
"\n"
"    }\n"
"  </style>\n"
"</head>\n"
"<body>\n"
"\t<div class=\"container\" align=\"center\" style=\"background-color: #f1f1f1;width: 1000px; height: 800px; \">\n"
"    <div class=\"row\">\n"
"      <div class=\"col-md-12\">\n"
"        <a href=\"#\"><img src=\"https://hoadondientu247.com/wp-content/uploads/2018/10/banner-VNNS.jpg\" width=\"1000px\" height=\"200px\"></a>\n"
"      </div>\n"
"    </div>\n"
"\t\t<div class=\"row\" style=\"background-color:#528B8B;\">\n"
"\t\t<ul class=\"nav nav-tabs\">\n"
"    \t<li class=\"nav-item\">\n"
"      \t\t\t<a class=\"nav-link\" data-toggle=\"tab\" href=\"#home\">Giới Thiệu </a>\n"
"   \t\t </li>\n"
"    \t<li class=\"nav-item\">\n"
"     \t\t <a class=\"nav-link active\" data-toggle=\"tab\" href=\"#menu1\">Bật tắt Led </a>\n"
"    \t</li>\n"
" \t </ul>\n"
" \t</div>\n"
"\n"
"  <!-- Tab panes -->\n"
"  <div class=\"tab-content\">\n"
"\n"
"    \t<div id=\"home\" class=\"container tab-pane fade\"><br>\n"
"    \t\t<div class=\"row\"><marquee width=\"50%\"><span style=\"color: #440000;\">Chào mừng bạn đến với môn thực hành chuyên sâu </span></marquee></div>\n"
"    \t\t<div class=\"row\" style=\"padding-top: 50px;\">\n"
"      \t\t\t<div class=\"col-md-2\" > <!--lay 3 cot dau tien-->\n"
"        <img src=\"https://www.easons.com/globalassets/book-covers/manunited_annual_2018.jpg\" width = \"300\" height =\"300\" style=\"border-radius: 30px;\" >\n"
"     </div>\n"
"    <div class=\"col-md-10\" style=\"padding-left: 150px;\">\n"
"          <font color = \"#003333\">\n"
"          \t<h1 style=\"font-weight:bold;\">THỰC HÀNH CHUYÊN SÂU</h1>\n"
"            <span>Họ và tên: Vũ Văn Chung</span><br/>\n"
"            <span>Ngày sinh : 30/3/1995</span><br/>\n"
"            <span>Mã sinh viên: B15DCDT019</span><br/>\n"
"            <span>Email: vuvanchungptit@gmail.com</span><br/>\n"
"            <span>Chuyên ngành: Điện tử máy tính </span>\n"
"\n"
"          </font>\n"
"    \t\t</div>\n"
"\t\t</div>\n"
"\t</div>\n"
"    <div id=\"menu1\" class=\"container tab-pane active\" style=\"padding-top: 80px; padding-left: 50px;\"><br>\n"
"    \t<h1 style=\"text-align: center; color: #004400;\">LED SỐ 1</h1>\n"
"    \t<br/>\n"
"     \t<div class=\"row\">\n"
"        <div class=\"col-md-4\">\n"
"        <a href=\"/led1On\"><button type=\"button\" class=\"btn btn-danger\" onclick=\"document.getElementById('myimage').src='http://bestanimations.com/HomeOffice/Lights/Bulbs/animated-light-bulb-gif-29.gif'\">ON</button></a>\n"
"        </div>\n"
"        <div class=\"col-md-4\">\n"
"        <img id=\"myimage\" src=\"https://www.freeiconspng.com/uploads/light-bulb-png-bulb-png1243-0.png\" style=\"width:100px\">\n"
"      </div>\n"
"      <div class=\"col-md-4\">\n"
"        <a href=\"/led1Off\"><button type=\"button\" class=\"btn btn-dark\" onclick=\"document.getElementById('myimage').src='https://www.freeiconspng.com/uploads/light-bulb-png-bulb-png1243-0.png'\">OFF</button></a>\n"
"      </div>\n"
"      </div>\n"
"\n"
"     \t<h1 style=\"text-align: center; color: #004400; padding-top: 120px;\">ĐIỀU CHỈNH ĐỘ SÁNG CỦA LED </h1>\n"
"     \t<div class=\"row\">\n"
"     \t\t<div class=\"col-md-4\">\n"
"     \t\t<a href=\"led1+\"><button type=\"button\" class=\"btn btn-danger\" onclick=\"document.getElementById('myimage').src='http://bestanimations.com/HomeOffice/Lights/Bulbs/animated-light-bulb-gif-29.gif'\">Tăng</button></a>\n"
"     \t\t</div>\n"
"     \t\t<div class=\"col-md-4\">\n"
"\t\t\t\t<img id=\"myimage\" src=\"https://www.freeiconspng.com/uploads/light-bulb-png-bulb-png1243-0.png\" style=\"width:100px\">\n"
"\t\t\t</div>\n"
"\t\t\t<div class=\"col-md-4\">\n"
"\t\t\t\t<a href=\"led1-\"><button type=\"button\" class=\"btn btn-dark\" onclick=\"document.getElementById('myimage').src='https://www.freeiconspng.com/uploads/light-bulb-png-bulb-png1243-0.png'\">Giảm</button></a>\n"
"\t\t\t</div>\n"
"     \t</div>\n"
"    </div>\n"
"</div>  \n"
"<!-- Footer -->\n"
"<footer class=\"page-footer font-small blue\" style=\"background-color: #D3D3D3;\">\n"
"\n"
"  <!-- Copyright -->\n"
"  <div class=\"footer-copyright text-center py-3\">© Bản quyền thuộc:\n"
"    <a href=\"#\" style=\"color: #808080;\"> Vũ Văn Chung </a>\n"
"  </div>\n"
"  <!-- Copyright -->\n"
"\n"
"</footer>\n"
"<!-- Footer -->\n"
"\t</div>\n"
"\n"
"</body>\n"
"</html>"
};
ESP8266WebServer server(80);

int a = 255;
int b = 100;

void handleRoot() {
  server.send_P(200, "text/html", index_html);
}

void setup(void){
  pinMode(D1, OUTPUT);  //led chân D1
  pinMode(D2, OUTPUT);
    //float h = dht.readHumidity();    //Đọc độ ẩm
  //float t = dht.readTemperature(); //Đọc nhiệt độ

   //String req = client.readStringUntil('\r');
  //Serial.println(req);
  //client.flush();

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }
    server.on("/", [](){
    server.send(200, "text/html", index_html);
  });
   server.on("/led1On", [](){
    server.send(200, "text/html", index_html);

    digitalWrite(D1, HIGH);
    delay(1000);
  });
     server.on("/led1+", [](){
    server.send(200, "text/html", index_html);

    analogWrite(D0, a);
    a+= b;
    delay(1000);
  });
    server.on("/led1-", [](){
    server.send(200, "text/html", index_html);

    analogWrite(D0, a);
    a -= b;
    delay(1000);
  });
  server.on("/led1Off", [](){
    server.send(200, "text/html", index_html);

    digitalWrite(D1, LOW);
    delay(1000); 
    });

  server.on("/", handleRoot);
  
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}
