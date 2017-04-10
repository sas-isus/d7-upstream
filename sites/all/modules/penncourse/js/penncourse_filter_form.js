/**
 * @file
 * penncourse_course_table.js
 *
 * JS for course filter form behaviors
 */

(function ($) {
    $(document).ready(function(){
        var filterForm = $('form#penncourse-filter-form')
        filterForm.delegate('select', 'change', function() {
            // alter form action and submit
            var action = filterForm.attr('action');

            // split URL on /pc (penncourse root path)
            var actionArray = action.split('/pc');

            action = actionArray[0] + '/pc/term/' + filterForm.find('select#edit-term').val() +
                '/subject/' + filterForm.find('select#edit-subject').val() +
                '/level/' + filterForm.find('select#edit-level').val();

            filterForm.attr('action', action);
            filterForm.submit();
        });
    });

})(jQuery);