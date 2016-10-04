$(document).ready(function() {
	$('#myswitch').switchable({ checked_color: '#ffec82', click: testing124 });
	$('#myswitch1').switchable({ checked_color: '#ffec82', click: changed1 });

	function testing124(ev, checked) {
		if (checked) {
			$('#second').html("<b style='color: green'>ON</b>");
		} else {
			$('#second').html("<b style='color: red'>OFF</b>");
		}
	}

	function changed1(ev, checked) {
		if (checked) {
			$('#third').html("<b style='color: green'>ON</b>");
		} else {
			$('#third').html("<b style='color: red'>OFF</b>");
		}
	}

	setInterval(function() {
		
	}, 50000);

});

