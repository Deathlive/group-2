$(function() {
    // $("#myModal").modal("hide");
    $("#myModal").modal("show");

    $("#phone").forceNumbericOnly();
    $("#postal").forceNumbericOnly();

    $("#myform1").submit(function() {
        push();
        $("#myModal").modal("hide");
        return false;
    });

    $("#myform2").submit(function() {
        pushTable();
        // $("html, body").animate({ scrollTop: $(document).height() }, 800);

        $('#sendmessage').hide();
        $('#table-box').hide();
        $('#output-box').hide();

        $("#sendmessage").fadeIn(800);
        $("#table-box").fadeIn(3000);
        $("#output-box").slideDown(1000);

        return false;
    })

});

function push() {
    $("#hname").html($("#name").val());
    $("#hlname").html($("#lname").val());
}

function pushTable() {
    $("#name1").html($("#prenam").val());
    $("#name2").html($("#nam").val());
    $("#phonenum").html($("#phone").val());
    $("#citi").html($("#ville").val());
    $("#addr").html($("#adresse").val());
    $("#postcod").html($("#postal").val());
}

$.fn.forceNumbericOnly = function() {
    return this.each(function() {
        $(this).keydown(function(e) {
            var key = e.charCode || e.keyCode || 0;
            return (
                key == 8 ||
                key == 9 ||
                key == 46 ||
                (key >= 37 && key <= 40) ||
                (key >= 48 && key <= 57) ||
                (key >= 96 && key <= 105));
        });
    });
};