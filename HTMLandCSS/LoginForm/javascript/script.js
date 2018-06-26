$(function() {

    /* Modal show and hide if */
    if (sessionStorage.getItem("name") == null) {
        $("#myModal").modal("show");
    } else {
        Load();
    }

    /* Result load*/
    if (sessionStorage.getItem("myKey1") != null) {
        var contentsOfOldDiv = JSON.parse(sessionStorage["myKey1"]);
        $("#resultBox").html(contentsOfOldDiv);
    }

    /* Login Form submit function */
    $("#myform1").submit(function() {
        if ($("#click_me").is(":checked")) {
            $("#title").html("Hi Mr.");
        }

        if ($("#or_me").is(":checked")) {
            $("#title").html("Hi Mrs.");
        }

        push();
        Save();
        $("#myModal").modal("hide");
        return false;
    });

    /* Contact Form submit function */
    $("#myform2").submit(function() {
        addResult();
        resultSave();
        clearInput();

        $("#sendmessage").hide();
        $("#sendmessage").fadeIn(800);
        $("#sendmessage").fadeOut(800);

        return false;
    })

});

/* Push name and surname to header */
function push() {
    $("#hname").html($("#name").val());
    $("#hlname").html($("#lname").val());
}

/* Clear input value in Contact Form */
function clearInput() {
    $("#prenam").val("");
    $("#nam").val("");
    $("#phone").val("");
    $("#ville").val("");
    $("#adresse").val("");
    $("#postal").val("");
}

/* Add input value of Contact Form to #resultBox div */
function addResult() {
    $("<div/>", { id: "rowBox", class: "row" }).append(
        $("<div/>", { id: "table-box", class: "col-md-12" }).append(
            $("<table/>", { class: "table table-hover" }).append(
                $("<tr/>").append(
                    $("<td/>").text("Name:"),
                    $("<td/>", { id: "name1" }).html($("#prenam").val())
                ),
                $("<tr/>").append(
                    $("<td/>").text("Surname:"),
                    $("<td/>", { id: "name2" }).html($("#nam").val())
                ),
                $("<tr/>").append(
                    $("<td/>").text("Phone:"),
                    $("<td/>", { id: "phonenum" }).html($("#phone").val())
                ),
                $("<tr/>").append(
                    $("<td/>").text("City:"),
                    $("<td/>", { id: "citi" }).html($("#ville").val())
                ),
                $("<tr/>").append(
                    $("<td/>").text("Address:"),
                    $("<td/>", { id: "addr" }).html($("#adresse").val())
                ),
                $("<tr/>").append(
                    $("<td/>").text("Postcode:"),
                    $("<td/>", { id: "postcod" }).html($("#postal").val())
                )
            )
        )
    ).appendTo("#resultBox");
}

/* Save name and surname at header */
function Save() {
    gender = "Male";

    if ($("#click_me").is(":checked")) {
        gender = "Male";
    }
    if ($("#or_me").is(":checked")) {
        gender = "Female";
    }

    sessionStorage.setItem("name", $("#name").val());
    sessionStorage.setItem("lname", $("#lname").val());
    sessionStorage.setItem("gender", gender);
    Load();
}

/* Load name and surname at header */
function Load() {
    var name1 = sessionStorage.getItem("name");
    var name2 = sessionStorage.getItem("lname")

    if (sessionStorage.getItem("gender") == "Male") {
        $("#title").html("Hi Mr.");
    }
    if (sessionStorage.getItem("gender") == "Female") {
        $("#title").html("Hi Mrs.");
    }

    $("#hname").text(name1);
    $("#hlname").text(name2);
}

/* Save result rowBox at resultBox div */
function resultSave() {
    var json1 = JSON.stringify($("#resultBox").html());
    sessionStorage.setItem("myKey1", json1);
}