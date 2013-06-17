var scale = 0;
var raw_scale = 0;
var index = 0;



$(function(){
  $("li.list-item").hide();
  // Find button
  $("#btn-find").on("tap", function(){
                    if($("#btn-find").hasClass("find")){
                    k.find();
                    } else {
                    k.disconnect();
                    
                    // change find button
                    $("#btn-find")
                    .addClass("find")
                    .html("Find konashi")
                    ;
                    
                    // hide uart panel
                    $("li.list-item").hide();
                    }
                    
                    //$("li.list-item").removeClass("index");
                    index = 0;
                    });
  
  $("li.list-divider").on("tap", function(){
                          $(this).next().toggle();
                       });
  
  $("li.list-item").on("tap", function(){
                       if ($(this).hasClass("index")){
                       index++;
                       
                       if ($("li.list-item").size() > index) {
                       $(this)
                       .removeClass("index")
                       .toggle();
                       
                       $("li.list-item").eq(index)
                       .addClass("index")
                       .toggle();
                       
                       var p = $("li.list-divider").eq(Math.max(0,index-1)).offset().top;
                       $("html,body").animate({ scrollTop: p }, "slow");
                       
                       }
                       }
                       });
  
//  $("#uart-baud-2k4").on("change", function(){
//                         k.uartMode(k.KONASHI_UART_DISABLE);
//                         k.uartBaudrate(k.KONASHI_UART_RATE_2K4);
//                         k.uartMode(k.KONASHI_UART_ENABLE);
//                         });
  
//  $("#uart-baud-9k6").on("change", function(){
//                         k.uartMode(k.KONASHI_UART_DISABLE);
//                         k.uartBaudrate(k.KONASHI_UART_RATE_9K6);
//                         k.uartMode(k.KONASHI_UART_ENABLE);
//                         });
  
//  $("#btn-tx-char").on("tap", function(){
//                       if($("#uart-tx-char").val()!=""){
//                       k.uartWrite($("#uart-tx-char").val().charCodeAt(0));
//                       }
//                       });
  
//  $("#btn-tx-str").on("tap", function(){
//                      if($("#uart-tx-str").val()!=""){
//                      var str=$("#uart-tx-str").val();
//                      for(i=0;i<str.length;i++){
//                      k.uartWrite(str.charCodeAt(i));
//                      }
//                      }
//                      });
  
//  $("#btn-tx-hex").on("tap", function(){
//                      if($("#uart-tx-hex").val()!=""){
//                      k.uartWrite(parseInt($("#uart-tx-hex").val(),16));
//                      }
//                      });
  
//  $("#btn-clear-rx").on("tap", function(){
//                        $("#uart-rx-text").html("");
//                        $("#uart-rx-hex").html("");
//                        });
  
  k.ready(function(){
          // change find button
          $("#btn-find")
          .removeClass("find")
          .html("Disconnect konashi")
          ;
          
          // show pio list
          index = 0;
          $("li.list-item").eq(0)
          .addClass("index")
          .show()
          ;
          
          // configure UART
          k.uartBaudrate(k.KONASHI_UART_RATE_9K6);
          k.uartMode(k.KONASHI_UART_ENABLE);
          });
  
  k.completeUartRx(function(data){
                   // $("#uart-rx-hex").html($("#uart-rx-hex").html()+ parseInt(data.value).toString(16)+" | ");
                   
                   if (data.value == 13) { return; }
                   if (data.value == 10) {
//                   $("#uart-rx-text").html(scale);
                   scale = raw_scale;
                   raw_scale = 0;
                   return;
                   }
                   raw_scale = 10*raw_scale + parseInt(String.fromCharCode(data.value));
                   
//                   $("#uart-rx-text").html($("#uart-rx-text").html()+data.value.toString());
//                   $("#uart-rx-text").html($("#uart-rx-text").html()+String.fromCharCode(data.value));
                   });
  
  //k.showDebugLog();
  });
