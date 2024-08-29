//O document ready verifica se a página já carregou antes de executar o código
$(document).ready(function (){

    $(".icon").on("click",function (){
        console.log("cli");
        //Se o menu estiver fechado abrir o menu caso contrario fechar
        if( $(".links1").css("display") == "none" ){
            $(".links1").css("display","block");
        }else{
            $(".links1").css("display","none");
        }
    });    
    
    $(".icon").on("click",function (){
        console.log("cli");
        //Se o menu estiver fechado abrir o menu caso contrario fechar
        if( $(".topnav").css("display") == "none" ){
            $(".topnav").css("display","block");
        }else{
            $(".topnav").css("display","none");
        }
    });

    var myIndex = 0;
carousel();

function carousel() {
  var i;
  var x = document.getElementsByClassName("mySlides");
  for (i = 0; i < x.length; i++) {
    x[i].style.display = "none";  
  }
  myIndex++;
  if (myIndex > x.length) {myIndex = 1}    
  x[myIndex-1].style.display = "block";  
  setTimeout(carousel, 3000); // Change image every 2 seconds
}
});