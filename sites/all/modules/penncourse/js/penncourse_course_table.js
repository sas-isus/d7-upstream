/**
 * @file
 * penncourse_course_table.js
 *
 * JS for course section table behaviors
 */

(function ($) {
    $(document).ready(function(){
        prepareCourseSectionTable('div.view-pc-section-table');
        // courseSectionTable.init();
    });

    function prepareCourseSectionTable(element_class) {
        var viewTable = $(element_class);
        viewTable.find('th.views-field-term-node-tid').remove();
        viewTable.find('th.views-field-field-pc-descr').remove();
        viewTable.find('th.views-field-field-pc-descr-1').remove();
        viewTable.find('th.views-field-field-pc-xlist').remove();
        viewTable.find('th.views-field-field-pc-dist-req').remove();
        viewTable.find('th.views-field-field-pc-sec-reg-ctrl').remove();
        viewTable.find('th.views-field-field-pc-syllabus').remove();
        viewTable.find('th.views-field-field-pc-syllabus-url').remove();
        viewTable.find('th.views-field-field-pc-syllabus-url-1').remove();
        viewTable.find('th.views-field-edit-node').remove();
        $(viewTable).find('tr').each(function( index ) {
            prepareCourseSectionRow(this);
        });
        viewTable.delegate('tr', 'click', '', function() {
            sectionRowBehavior(this);
        });
        viewTable.delegate('a', 'click', '', function( event ) {
            event.stopPropagation();
        });
        $(viewTable).find('td').css('cursor', 'pointer');
    }

    /**
     * move the description and taxonomy tags into data elements for retrieval later
     * @param row
     */
    function prepareCourseSectionRow(row) {
        $(row).data({
            taxonomyTerms : $(row).find('td.views-field-term-node-tid').html(),
            courseDescription : $(row).find('td.views-field-field-pc-descr').html(),
            sectionDescription : $(row).find('td.views-field-field-pc-descr-1').html(),
            xlist : $(row).find('td.views-field-field-pc-xlist').html(),
            fulfills : $(row).find('td.views-field-field-pc-dist-req').html(),
            registrationNotes : $(row).find('td.views-field-field-pc-sec-reg-ctrl').html(),
            syllabus : $(row).find('td.views-field-field-pc-syllabus').html(),
            sectionSyllabusURL : $(row).find('td.views-field-field-pc-syllabus-url').html(),
            courseSyllabusURL : $(row).find('td.views-field-field-pc-syllabus-url-1').html(),
            editLink : $(row).find('td.views-field-edit-node').html()
        });

        $(row).find('td.views-field-term-node-tid').remove();
        $(row).find('td.views-field-field-pc-descr').remove();
        $(row).find('td.views-field-field-pc-descr-1').remove();
        $(row).find('td.views-field-field-pc-xlist').remove();
        $(row).find('td.views-field-field-pc-dist-req').remove();
        $(row).find('td.views-field-field-pc-sec-reg-ctrl').remove();
        $(row).find('td.views-field-field-pc-syllabus').remove();
        $(row).find('td.views-field-field-pc-syllabus-url').remove();
        $(row).find('td.views-field-field-pc-syllabus-url-1').remove();
        $(row).find('td.views-field-edit-node').remove();
        // console.log($(row).data().courseDescription);
        // console.log('test');
    }

    /**
     * display the additional section detail data in a temporary row
     * @param row
     */
    function sectionRowBehavior(row) {
        var activeRow = $(row);
        if (activeRow.hasClass('active')) {
            $('tr.pc-course-detail').fadeOut().remove();
            activeRow.removeClass('active');
        }
        else {
            $('tr.pc-course-detail').fadeOut().remove();
            $('tr.active').removeClass('active');
            activeRow.addClass('active');
            console.log($(row).data().courseDescription);
            console.log($(row).data().editLink);
            console.log($(row).data().xlist);
            console.log($(row).data().taxonomyTerms);
            var xlist = $(row).data().xlist;
            console.log($(xlist).text());
            var newRow = '<tr class="pc-course-detail" style="display:none;"><td colspan="5" class="pc-course-detail">';
            if (activeRow.data().sectionDescription.trim()) {
                newRow += '<div class="field"><div class="pc-section-description">' + activeRow.data().sectionDescription + '</div></div>';
            }
            else if (activeRow.data().courseDescription.trim()) {
                newRow += '<div class="field"><div class="pc-course-description">' + activeRow.data().courseDescription + '</div></div>';
            }
            if (activeRow.data().editLink) {
                newRow += '<div class="field"><div class="pc-edit">' + activeRow.data().editLink + '</div></div>';
            }
            if (activeRow.data().xlist.trim() != "<ul></ul>") {
                newRow += '<div class="field"><div class="pc-xlist field-label">Crosslistings</div>';
                newRow += '<div class="pc-xlist">' + activeRow.data().xlist + '</div></div>';
            }
            if (activeRow.data().taxonomyTerms.trim()) {
                newRow += '<div class="field"><div class="pc-taxonomy-terms field-label">Course Themes</div>';
                newRow += '<div class="pc-taxonomy-terms">' + activeRow.data().taxonomyTerms + '</div></div>';
            }
            if (activeRow.data().fulfills.trim()) {
                newRow += '<div class="field"><div class="pc-dist-req field-label">Fulfills</div>';
                newRow += '<div class="pc-dist-req">' + activeRow.data().fulfills + '</div></div>';
            }
            if (activeRow.data().registrationNotes.trim()) {
                newRow += '<div class="field"><div class="pc-sec-reg-ctrl field-label">Registration Notes</div>';
                newRow += '<div class="pc-sec-reg-ctrl">' + activeRow.data().registrationNotes + '</div></div>';
            }
            if (activeRow.data().syllabus.trim()) {
                newRow += '<div class="field"><div class="pc-syllabus field-label">Syllabus</div>';
                newRow += '<div class="pc-syllabus">' + activeRow.data().syllabus + '</div></div>';
            }
            if (activeRow.data().sectionSyllabusURL.trim()) {
                newRow += '<div class="field"><div class="pc-syllabus-url field-label">Syllabus</div>';
                newRow += '<div class="pc-syllabus-url">' + activeRow.data().sectionSyllabusURL + '</div></div>';
            }
            else if (activeRow.data().courseSyllabusURL.trim()) {
                newRow += '<div class="field"><div class="pc-syllabus-url field-label">Syllabus</div>';
                newRow += '<div class="pc-syllabus-url">' + activeRow.data().courseSyllabusURL + '</div></div>';
            }
            // '<div class="pc-edit">' + '<a href="' + activeRow.data().editLink[1].attributes[0].nodeValue + '">' + activeRow.data().editLink.text() + '</a></div>' +
            // '<div class="pc-terms">' + '<a href="' + activeRow.data().taxonomyTerms.text() + + activeRow.data().taxonomyTerms.text() + '</div>' +
            newRow += '</td></tr>';
            activeRow.after(newRow);
            $('tr.pc-course-detail').fadeIn(400);
        }
    }

    /* var courseSectionTable = {
     init : function() {
     $('div.view-pc-section-table tr').each(courseSectionRow.init(this));
     }
     };

     var courseSectionRow = {
     init : function(row) {
     $(row).data({
     taxonomyTerms : $(row).find('td.views-field-term-node-tid').contents(),
     courseDescription : $(row).find('td.views-field-field-pc-descr').contents(),
     sectionDescription : $(row).find('td.views-field-field-pc-descr-1').contents()
     });

     console.log($(row).data().courseDescription);
     console.log('test');
     }
     }; */
})(jQuery);